int lengthOfLongestSubstring(char * s){
    int maxlen = 0;
    int start = 0;
    int end = 1;
    char hash['~' - ' ' + 1] = { 0 };
    // enqueue first char into the hash
    if (*s != '\0'){
        hash[s[start] - ' ']++;
    }
    while (s[start] != '\0'){
        // find the first repeated char
        while ((s[end] != '\0') && (hash[s[end] - ' '] < 1)){
            hash[s[end] - ' ']++;
            end++;
        }
        // calculate the len
        int len = end - start; 
        if (len > maxlen){
            maxlen = len;
        }
        // remove start element from the hash and move to the next one
        hash[s[start] - ' ']--;
        start++;
    }
    return maxlen;
}