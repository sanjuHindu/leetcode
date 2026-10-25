class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize closest sum as sum of first three elements
        int closest = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // Update closest if current sum is nearer to target
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // Exact match
                    return sum;
                }
            }
        }
        return closest;
    }
};
