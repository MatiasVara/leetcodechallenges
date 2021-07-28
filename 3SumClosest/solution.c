int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    int mindif = INT_MAX;
    int value;
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    for (int j=0;j<numsSize-2;j++){
        int * start = &nums[j+1];
        int * end = &nums[numsSize - 1];
        while (start < end){
            int sum = nums[j] + (*start) + (*end);
            if (abs(target-sum) < mindif){
                mindif = abs(target-sum);
                value = sum;
            }
            if (sum >= target){
                end -=1;
            }else{
                start +=1;
            }
        }
    }
    return value;
}
