class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // adjacent check
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }

        // circular check
        if (nums[n - 1] > nums[0]) {
            count++;
        }

        // simple if-else
        if (count <= 1) {
            return true;
        } else {
            return false;
        }
    }
};
