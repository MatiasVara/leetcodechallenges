int trap(int* height, int heightSize){
    int start =0;
    int count = 0;
    while (start < heightSize-1){
        int end=start+1;
        int blacks = height[start];
        int largest = 0;
        int pos = 0;
        int currentb = 0;
        while ((end < heightSize) && (height[start] > height[end])){
          if (height[end] > largest){
            largest = height[end];
            pos = end;
            currentb = blacks;
          }    
          blacks += height[end];
          end++;
        }
        if (end < heightSize){
            count += (end - start) * height[start] - blacks; 
            start = end; 
        } else{
            // this handles cases like [4, 2, 3]
            if (pos > start){
                count += (pos - start - 1) * largest - (currentb - height[start]);
                start = pos;
            } else {
                start++;
            }
        }
    }
    return count;
}
