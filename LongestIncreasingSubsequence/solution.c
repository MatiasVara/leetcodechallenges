int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int hash[2501];

int lengthOfLIS2(int* nums, int numsSize, int pos){
    int ret = 0;
    if (hash[pos] != 0){
        return hash[pos];
    }
    if (numsSize == 0){
        return 0;
    }
    for (int j=1; j<numsSize; j++){
        if (nums[0] < nums[j]){
            int ret1 = lengthOfLIS2(&nums[j], numsSize - j, pos + j);
            ret = max(ret, ret1);
        }
    }
    // the +1 comes from counting my position too
    hash[pos] = ret + 1;
    return ret + 1;    
}

int lengthOfLIS(int* nums, int numsSize){
    int ret = 0;
    for (int j=0; j< 2501; j++){
        hash[j] =0;
    }
    // the subsequence can start anywhere
    for(int i = 0; i<numsSize; i++){
        int ret1 = lengthOfLIS2(&nums[i], numsSize - i, i);
        ret = max(ret, ret1);
    }
    return ret;    
}
