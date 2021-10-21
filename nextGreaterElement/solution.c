int hash[10001];
int stack[1001];
int last_index;

bool isempty(){
    if (last_index ==0){
        return true;
    }
    return false;
}

bool isfull(){
    if (last_index == 1001){
        return true;
    }
    return false;
}

bool push(int val){
    if (isfull() == false){
        stack[last_index] = val;
        last_index++;
        return true;
    }
    return false;
}

// stack must have at least one element
int peektop(){
    return stack[last_index-1];
}

bool pop(int * val){
    if (isempty() == false){
        last_index--;
        *val = stack[last_index];
        return true;
    }
    return false;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    last_index = 0;
    for (int j=nums2Size-1; j >= 0; j--){
        while ((isempty() == false) && (peektop() < nums2[j])){
            int tmp;
            pop(&tmp);
        }
        if (isempty() == true){
            hash[nums2[j]] = -1;
        } else{
            hash[nums2[j]] = peektop();
        }
        push(nums2[j]);
    }
    int * ret = (int*)malloc(sizeof(int) * nums1Size);
    for (int j=0; j<nums1Size; j++){
        ret[j] = hash[nums1[j]];
    }
    *returnSize = nums1Size;
    return ret;
}