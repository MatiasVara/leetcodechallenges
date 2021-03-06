struct node{
    char val;
    struct node * next;
};

int hash['z' - '0' + 1];
struct node * hash_frec[500001];

char * frequencySort(char * s){
    int len;
    len = 0;
    // clean the hash used to store the frecuency of
    // each char. The chars are the key of the hash.
    for (int j=0; j<'z' - '0' + 1; j++){
        hash[j] = 0;
    }
    // clean the hash that keeps the frecuency of each char
    // The key is the frecuency
    for (int j=0; j<500001; j++){
        hash_frec[j] = NULL;
    }
    // store the frecuency of each char
    while (*s != '\0'){
        len++;
        hash[*s - '0'] += 1;
        s++;
    }
    // store each char in its corresponding frecuency
    // we have to handle colissions so I use a simple linked list
    for (int j=0; j< 'z'-'0' + 1; j++){
        if (hash[j] > 0){
            struct node * tmp = (struct node*)malloc (sizeof(struct node));
            tmp->val = j;
            tmp->next = hash_frec[hash[j]];
            hash_frec[hash[j]] = tmp;
        }
    }
    
    char * r = malloc((len+1) * sizeof(char));
    char * tmp = r;
    
    // walk the frecuency hash from the more to the less frecuent
    for (int frec=500000; frec>=0; frec--){
        // get the head of the linked list
        struct node * next_node = hash_frec[frec];
        while (next_node != NULL){
            for (int p=0; p<frec; p++){
                *r = (char)(next_node->val + '0');
                r++;
            }
            struct node * release_node = next_node;
            next_node=next_node->next;
            free(release_node);
        }
    }
    
    *r = '\0';
    return tmp;
}
