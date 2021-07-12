struct myhash{
    char * str;
    int gen;
};

struct myhash cache[1001];
int elements;

struct myhash * getcache(char * str){
    for (int j = 0; j < elements; j++){
        if (!strcmp(cache[j].str, str)){
            return &cache[j]; 
        }
    }
    return NULL;
}

void putcache(char * str, int gen){
    cache[elements].str = str;
    cache[elements].gen = gen;
    elements++;
}

void strremovedi(int i, char * dst, char * src){
    int c = 0;
    while (src[c] != '\0'){
        if (c != i){
            *dst = src[c];
            dst++;
        }
        c++;
    }
    *dst = '\0';
}

int cmpfunc (const void * a, const void * b) {
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    int fa = strlen(aa);
    int fb = strlen(bb);
    return (fa > fb) - (fa < fb);
}

int max(int a, int b){
    if (a>b){
        return a;
    } else {
        return b;
    }
}

int longestStrChain(char ** words, int wordsSize){
    elements = 0;
    int maxi = INT_MIN;
    qsort(words, wordsSize, sizeof(char*), cmpfunc);
    for (int j=0; j < wordsSize;j++){
        int len = strlen(words[j]);
        int longest = 0;
        for (int i = 0; i < len; i++){
            char tmp[17];
            struct myhash * t;
            strremovedi(i, tmp, words[j]);
            t = getcache(tmp);
            if (t){
                longest = max(longest, t->gen);
            }
        }
        longest += 1;
        putcache(words[j], longest);
        maxi = max(maxi, longest);
    }
    return maxi;
}
