class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // If all are odd OR all are even
        if (!hasOdd || !hasEven)
            return true;

        // If both parities exist, we can make all elements odd
        return true;
    }
};