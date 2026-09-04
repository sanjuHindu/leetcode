class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int suffixMin = nums[n - 1];
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            if (i == n - 1) {
                suffixMin = nums[i];
            } else {
                suffixMin = *min_element(nums.begin() + i, nums.end());
            }

            if (prefixMax - suffixMin <= k) {
                return i;
            }
        }

        return -1;
    }
};