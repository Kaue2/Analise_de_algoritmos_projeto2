int lengthOfLIS(int* nums, int nums_size) {
    if (nums_size == 0) return 0;
    
    int dp[nums_size];
    int maior_global = 1;
    
    for (int i = 0; i < nums_size; i++) {
        dp[i] = 1;
        
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        
        if (dp[i] > maior_global) {
            maior_global = dp[i];
        }
    }
    
    return maior_global;
}