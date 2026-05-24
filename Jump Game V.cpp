class Solution {
public:
    
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        
        // already computed
        if(dp[i] != -1)
            return dp[i];

        int n = arr.size();

        // minimum answer = current index itself
        int ans = 1;

        // move right
        for(int j = i + 1; j <= min(n - 1, i + d); j++) {

            // blocked
            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        // move left
        for(int j = i - 1; j >= max(0, i - d); j--) {

            // blocked
            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

    
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for(int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};
