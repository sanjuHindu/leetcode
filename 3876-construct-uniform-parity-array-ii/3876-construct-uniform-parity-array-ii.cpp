class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                minOdd = min(minOdd, x);
            else
                minEven = min(minEven, x);
        }

        // Already all have the same parity.
        if (minOdd == INT_MAX || minEven == INT_MAX)
            return true;

        // If the smallest number is even, that even number
        // cannot be changed to odd, and the smallest odd
        // cannot be changed to even.
        //
        // If the smallest number is odd, every even number
        // can subtract this smaller odd number and become odd.
        return minOdd < minEven;
    }
};