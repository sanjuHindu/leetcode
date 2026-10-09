class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.length()) {
            // If character not present, insert and move right
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            // If duplicate found, remove left character
            else {
                st.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
