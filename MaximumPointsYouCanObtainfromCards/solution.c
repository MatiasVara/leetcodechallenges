int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int maxScore(int* cardPoints, int cardPointsSize, int k){
    int win = cardPointsSize - k;
    int totalsum=0;
    int maxsum = INT_MIN;
    int * PreFixSum = malloc (sizeof(int) * (cardPointsSize+1));
    PreFixSum[0] = 0;
    for (int j=1; j < cardPointsSize + 1; j++){
        PreFixSum[j] = PreFixSum[j-1] + cardPoints[j-1];
    }
    
    for (int j=0; j < cardPointsSize; j++){
        totalsum += cardPoints[j];
    }
    for (int start=0; start <= k; start++){
        int win_size = 0;
        win_size = PreFixSum[start + cardPointsSize - k] - PreFixSum[start]; 
        maxsum = max(maxsum, totalsum - win_size); 
    }
    free(PreFixSum);
    return maxsum;
}
