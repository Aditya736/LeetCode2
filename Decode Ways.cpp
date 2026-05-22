class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        
        // Reached end -> one valid decoding
        if(i == s.size()) {
            return 1;
        }

        // String starting with 0 is invalid
        if(s[i] == '0') {
            return 0;
        }

        // Already computed
        if(dp[i] != -1) {
            return dp[i];
        }

        // Take single digit
        int ways = solve(i + 1, s, dp);

        // Take two digits
        if(i + 1 < s.size()) {

            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                ways += solve(i + 2, s, dp);
            }
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};