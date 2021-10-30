struct triplet{
    int triple[3];
    struct triplet * next;
};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    struct triplet * head = NULL;
    int rows = 0;
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for (int i=0; i<numsSize-2; i++){
        if ((i > 0) && (nums[i] == nums[i-1])){
            continue;
        }
        int j = i + 1;
        int k = numsSize - 1;
        int target = nums[i] * (-1);
        while (j < k){
            if (nums[j] + nums[k] == target){
                 struct triplet * tmp = (struct triplet *)malloc (sizeof(struct triplet));
                 tmp->triple[0] = nums[j];
                 tmp->triple[1] = nums[k];
                 tmp->triple[2] = nums[i];
                 tmp->next = head;
                 head = tmp;
                 rows++;
                 k--;
                 while ((k>=0)&&(nums[k] == nums[k+1])){
                     k--;
                 }
                 j++;
                 while ((j<numsSize)&&(nums[j] == nums[j-1])){
                     j++;
                 }
            } else if (nums[j] + nums[k] > target){
                 k--;
                 while ((k>=0)&&(nums[k] == nums[k+1])){
                     k--;
                 }
            } else {
                 j++;
                 while ((j<numsSize)&&(nums[j] == nums[j-1])){
                     j++;
                 }
            }
        }
    }
    
    int ** triplets;
    triplets = (int**)malloc(sizeof(int*) * rows);
    
    for (int row = 0; row< rows; row++){
        triplets[row] = (int*)malloc(sizeof(int) * 3);
    }
    
    int curr_row = 0;
    while (head != NULL){
        triplets[curr_row][0] = head->triple[0];
        triplets[curr_row][1] = head->triple[1];
        triplets[curr_row][2] = head->triple[2];
        curr_row++;
        head = head->next;        
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int) * rows);
    for(int i = 0; i < rows; i++)
        (*returnColumnSizes)[i]=3;
    
    *returnSize = rows;
    
    return triplets;
}