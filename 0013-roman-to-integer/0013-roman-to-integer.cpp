class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && value[s[i]] < value[s[i + 1]]) {
                sum -= value[s[i]];
            } else {
                sum += value[s[i]];
            }
        }
        return sum;
    }
};
