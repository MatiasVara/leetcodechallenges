int hash[101];

int numDecodings2(char * s, int start, int len){
    int count = 0;
    // the value is already in the hash
    if (hash[start] != 2){
        return hash[start];
    }

    // valid string
    if (len == 0){
        return 1;
    }

    // invalid
    if (s[start] == '0'){
        return 0;
    }

    // one char size
    count += numDecodings2(s, start+1, len-1);

    // check two char size
    if (len > 1){
        int t = (s[start] - '0') * 10 + (s[start+1] - '0');
        if ((t > 0) && (t < 27)){
            count += numDecodings2(s, start+2, len-2);
        }
    }

    hash[start] = count;
    return count;
}


int numDecodings(char * s){
    for (int j=0; j< 101; j++){
        hash[j] = 2;
    }
    return numDecodings2(s, 0, strlen(s));
}
