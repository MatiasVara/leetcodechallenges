void moveZeroes(int* nums, int numsSize){
    int * p = &nums[0];
    int len = 0;
    for (int j=0; j< numsSize; j++){
        if (nums[j] != 0){
            *p = nums[j];
             p++;
        } else{
            len++;
        }
    }
    for (int j=numsSize-1; j>numsSize-1-len; j--){
        nums[j] = 0;
    }
}