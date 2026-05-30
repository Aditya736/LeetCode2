class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;

        long long val = 1;
        ans.push_back(1);

        for(int k = 1; k <= rowIndex; k++) {
            val = val * (rowIndex - k + 1) / k;
            ans.push_back((int)val);
        }

        return ans;
    }
};