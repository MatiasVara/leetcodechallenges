import requests
import json
# get token for hello-world image
req = requests.get("https://auth.docker.io/token?service=registry.docker.io&scope=repository:library/hello-world:pull")
j = json.loads(req.content)
payload = {
        "Authorization": "Bearer "+j["token"],
        "Accept": "application/vnd.docker.distribution.manifest.list.v2+json,pplication/vnd.docker.distribution.manifest.v2+json,application/vnd.docker.distribution.manifest.v1+json"
}
# get image manifest
req = requests.get("https://registry-1.docker.io/v2/library/hello-world/manifests/latest", headers=payload)
m = json.loads(req.content)
for manifest in m["manifests"]:
        # get the manifest depending on the architecture
        if manifest["platform"]["architecture"] == "amd64" and manifest["platform"]["os"] == "linux":
                digest=manifest["digest"]
                req = requests.get("https://registry-1.docker.io/v2/library/hello-world/manifests/"+digest, headers=payload)
                l = json.loads(req.content)
                # an image is made of several layers
                # download all layers
                img = 0
                for layer in l["layers"]:
                        payloadforimage = {
                                "Authorization": "Bearer "+j["token"],
                                "Accept": layer["mediaType"]
                        }
                        req = requests.get("https://registry-1.docker.io/v2/library/hello-world/blobs/"+layer["digest"], headers=payloadforimage)
                        # simply store layer with a number
                        f = open("layer"+str(img)+".tar.gz", "wb")
                        img=img+1
                        f.write(req.content)
                        f.close()
