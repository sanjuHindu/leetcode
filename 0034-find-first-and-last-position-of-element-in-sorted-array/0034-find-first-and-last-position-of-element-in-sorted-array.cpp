class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        if (left == -1) return {-1, -1};
        int right = findBound(nums, target, false);
        return {left, right};
    }
    
private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int lo = 0, hi = nums.size() - 1;
        int result = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                if (isFirst) {
                    hi = mid - 1;  // keep searching left
                } else {
                    lo = mid + 1;  // keep searching right
                }
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return result;
    }
};