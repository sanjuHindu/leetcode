class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Make minIdx the smaller index
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        // 1. Remove both from front
        int front = maxIdx + 1;

        // 2. Remove both from back
        int back = n - minIdx;

        // 3. Remove min from front and max from back
        int both = (minIdx + 1) + (n - maxIdx);

        return min({front, back, both});
    }
};