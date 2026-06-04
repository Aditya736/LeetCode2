class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev2, int prev1, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started]) {
            return dp[pos][prev2][prev1][started];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, 10, 10, false, newTight);

                totalCnt += child.cnt;
                totalWav += child.wav;
            } else {
                if (!started) {
                    Node child = dfs(pos + 1, 10, d, true, newTight);

                    totalCnt += child.cnt;
                    totalWav += child.wav;
                } else {
                    int add = 0;

                    if (prev2 != 10) {
                        if ((prev1 > prev2 && prev1 > d) ||
                            (prev1 < prev2 && prev1 < d)) {
                            add = 1;
                        }
                    }

                    Node child = dfs(pos + 1, prev1, d, true, newTight);

                    totalCnt += child.cnt;
                    totalWav += child.wav + 1LL * add * child.cnt;
                }
            }
        }

        Node ans = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            dp[pos][prev2][prev1][started] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};