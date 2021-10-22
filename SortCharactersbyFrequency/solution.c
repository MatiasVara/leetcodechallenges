struct node{
    int frec;
    char val;
};

struct node hash['z' - '0' + 1];

int cmpfunc (const void * a, const void * b) {
   return ( ((struct node*)b)->frec - ((struct node*)a)->frec );
}

char * frequencySort(char * s){
    int len;
    len = 0;
    for (int j=0; j<'z' - '0' + 1; j++){
        hash[j].frec = 0;
    }
    while (*s != '\0'){
        len++;
        hash[*s - '0'].frec += 1;
        hash[*s - '0'].val = *s;
        s++;
    }
    qsort(hash, 'z'-'0' + 1, sizeof(struct node), cmpfunc);
    char * r = malloc(sizeof(char) * len + 1);
    char * ret = r;
    for (int k=0; k < 'z' - '0' + 1; k++){
        for(int j=0; j<hash[k].frec;j++){
            *r = hash[k].val;
            r++;
        }
    }
    *r = '\0';
    return ret;
}
