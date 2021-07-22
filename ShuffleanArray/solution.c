typedef struct {
    int * original;
    int * suffle;
    int * used;
    int size;
    time_t t;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution * tmp;
    tmp = malloc(sizeof(Solution));
    tmp->original = malloc (sizeof(int) * numsSize);
    tmp->suffle = malloc (sizeof(int) * numsSize);
    tmp->used = malloc (sizeof(int) * numsSize);
    srand((unsigned) time(&tmp->t));
    tmp->size = numsSize;
    for (int j=0; j < numsSize; j++){
        tmp->original[j] = nums[j];
    }
    return tmp;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;
    return obj->original;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    int count = 0;
    *retSize = obj->size;
    for (int j=0; j<obj->size; j++){
        obj->used[j] = 0;
    } 
    while (count < obj->size){
        int pos = rand() % obj->size;
        if (obj->used[pos] == 0){
            obj->used[pos] = 1;
            obj->suffle[count] = obj->original[pos];
            count++;
        }
    }
    return obj->suffle;
}

void solutionFree(Solution* obj) {
    free(obj->original);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/