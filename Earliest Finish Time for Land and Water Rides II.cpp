class Solution {
public:
    long long solveOrder(vector<int>& start1, vector<int>& dur1,
                         vector<int>& start2, vector<int>& dur2) {

        int m = start2.size();

        vector<pair<long long,long long>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({start2[i], dur2[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);
        vector<long long> prefixMinDur(m);
        vector<long long> suffixMinFinish(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefixMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefixMinDur[i] =
                min(prefixMinDur[i - 1], rides[i].second);
        }

        suffixMinFinish[m - 1] =
            rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffixMinFinish[i] =
                min(suffixMinFinish[i + 1],
                    rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < start1.size(); i++) {

            long long A = (long long)start1[i] + dur1[i];

            int pos = upper_bound(starts.begin(),
                                  starts.end(),
                                  A) - starts.begin();

            if (pos > 0) {
                ans = min(ans,
                          A + prefixMinDur[pos - 1]);
            }

            if (pos < m) {
                ans = min(ans,
                          suffixMinFinish[pos]);
            }
        }

        return ans;
    }

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long landFirst =
            solveOrder(landStartTime, landDuration,
                       waterStartTime, waterDuration);

        long long waterFirst =
            solveOrder(waterStartTime, waterDuration,
                       landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};