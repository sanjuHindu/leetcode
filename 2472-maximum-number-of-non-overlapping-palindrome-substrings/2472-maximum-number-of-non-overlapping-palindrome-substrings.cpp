
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            // Carry forward: don't end a palindrome at this position
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Odd-length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break; // earliest valid palindrome is optimal
                }
                l--;
                r++;
            }

            // Even-length palindromes centered between i and i+1
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
                l--;
                r++;
            }
        }

        return dp[n];
    }
};

