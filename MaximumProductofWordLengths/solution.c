bool nocommonletters(char * s, char * b){
    int hash['z' - 'a' + 1] = {0};
    while (*s != '\0'){
        hash[*s-'a'] = 1;
        s++;
    };
    while (*b != '\0'){
        if (hash[*b -'a']){
            return false;
        }
        b++;
    };
    return true;
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int maxProduct(char ** words, int wordsSize){
    int maxi = 0;
    for (int j=0; j < wordsSize; j++){
        for (int i=0; i< wordsSize; i++){
            if (i != j){
                if (nocommonletters(words[i], words[j])){
                    maxi = max(maxi, strlen(words[i]) * strlen(words[j]));
                }
            }
        }
    }
    return maxi;
}