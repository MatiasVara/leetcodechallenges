int hash[1001] = {0};

int jumpp(int* nums, int pos, int numsSize){
    int path;
    int min_path = INT_MAX;
    
    if (hash[pos]) {
        return hash[pos];
    }
    
    if (numsSize <= 1){
        return 0;
    }
    for (int j = 1; j <= nums[0]; j++){
        if (((j < numsSize) && (nums[j] != 0)) || (j == numsSize -1)) {
            path = jumpp(&nums[j], pos + j, numsSize - j);
            if (path != INT_MAX) {
                path += 1;
            }
            if (path < min_path){
                min_path = path;
            }
        }
    }
    
    hash[pos] = min_path;
    return min_path;
}

int jump(int* nums, int numsSize){
    for (int j=0; j < 1000; j++){
        hash[j] = 0;
    }
    return jumpp(nums, 0, numsSize);
}
