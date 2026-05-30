class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> coords = {0};

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int m = coords.size();

        auto getIdx = [&](int x) {
            return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
        };

        set<int> obstacles;

        int MAX_POS = coords.back();

        obstacles.insert(0);
        obstacles.insert(MAX_POS);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        Fenwick bit(m);

        auto addGap = [&](int right, int gap) {
            int idx = getIdx(right);
            bit.update(idx, gap);
        };

        vector<int> obs(obstacles.begin(), obstacles.end());

        for (int i = 1; i < obs.size(); i++) {
            addGap(obs[i], obs[i] - obs[i - 1]);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int right = *it;
                int left = *prev(it);

                int best = bit.query(getIdx(left));

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto it = obstacles.find(x);

                int right = *next(it);
                int left = *prev(it);

                addGap(right, right - left);

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};