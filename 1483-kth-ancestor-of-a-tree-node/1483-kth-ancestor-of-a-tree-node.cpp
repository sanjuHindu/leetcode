class TreeAncestor {
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        up.assign(LOG, vector<int>(n, -1));

        // up[j][i] = 2^j-th ancestor of node i
        for (int i = 0; i < n; i++) {
            up[0][i] = parent[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int ancestor = up[j - 1][i];

                if (ancestor != -1) {
                    up[j][i] = up[j - 1][ancestor];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int j = 0;

        while (k > 0 && node != -1) {
            if (k & 1) {
                node = up[j][node];
            }

            k >>= 1;
            j++;
        }

        return node;
    }
};