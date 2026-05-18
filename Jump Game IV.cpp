class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();

        if(n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        // value -> all indices
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int idx = q.front();
                q.pop();

                // reached end
                if(idx == n - 1)
                    return steps;

                // i + 1
                if(idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // i - 1
                if(idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                // same value jumps
                for(auto nextIdx : mp[arr[idx]]) {

                    if(!vis[nextIdx]) {
                        vis[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }

                // IMPORTANT OPTIMIZATION
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};