class Solution {
public:
    using ll = long long;

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<ll, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        // Find first interval whose start > current end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while (l < r) {
                int mid = (l + r) / 2;

                if (a[mid][0] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        // dp[i][k] = maximum score from i onward selecting at most k intervals
        vector<vector<ll>> dp(n + 1, vector<ll>(5, 0));

        // Store selected indices for reconstruction
        vector<vector<vector<int>>> path(
            n + 1, vector<vector<int>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Skip current interval
                dp[i][k] = dp[i + 1][k];
                path[i][k] = path[i + 1][k];

                // Take current interval
                ll takeScore = a[i][2] + dp[nxt[i]][k - 1];
                vector<int> takePath = path[nxt[i]][k - 1];
                takePath.push_back(a[i][3]);

                vector<int> skipPath = path[i + 1][k];

                sort(takePath.begin(), takePath.end());
                sort(skipPath.begin(), skipPath.end());

                if (takeScore > dp[i][k] ||
                    (takeScore == dp[i][k] && takePath < skipPath)) {
                    dp[i][k] = takeScore;
                    path[i][k] = takePath;
                }
            }
        }

        return path[0][4];
    }
};