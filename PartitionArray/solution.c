
int min(int a, int b){
    if (a>b){
        return b;
    } else{
        return a;
    }
}

int partitionDisjoint(int* nums, int numsSize){
    int pos;
    int max_left = nums[0];
    int * minright = malloc (sizeof(int) * numsSize);
    
    minright[numsSize-1] = nums[numsSize-1];
    
    for (int j=numsSize-1;j>0;j--){
        minright[j-1] = min(minright[j], nums[j-1]);
    }
    
    for (pos=0; pos<numsSize-1;pos++){
        if (nums[pos] > max_left){
            max_left = nums[pos];
        }
        int min_right = minright[pos+1];
        if (max_left <= min_right){
            break;
        }
    }
    free(minright);
    return pos + 1;
}
