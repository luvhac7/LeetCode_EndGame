class Solution {
public:
    vector<int> parents, rankv;

    int find_par(int u) {
        if (parents[u] == u) return u;
        return parents[u] = find_par(parents[u]);
    }

    void dsu_union(int u, int v) {
        u = find_par(u);
        v = find_par(v);
        if (u == v) return;
        if (rankv[u] < rankv[v]) swap(u, v);
        parents[v] = u;
        if (rankv[u] == rankv[v]) rankv[u]++;
    }

    bool solve(vector<vector<int>>& edges, int k, int mid, int n) {
        priority_queue<tuple<int,int,int>> pq;

        // ---- mandatory edges ----
        for (auto &e : edges) {
            if (e[3] == 1) {
                pq.push({e[2], e[0], e[1]});
            }
        }

        int cnt = 0;

        while (!pq.empty()) {
            auto [s, u, v] = pq.top();
            pq.pop();

            if (s < mid) return false;
            if (find_par(u) == find_par(v)) return false;

            dsu_union(u, v);
            cnt++;
        }

        if (cnt == n - 1) return true;

        // ---- optional edges ----
        while (!pq.empty()) pq.pop();

        for (auto &e : edges) {
            if (e[3] == 0) {
                pq.push({e[2], e[0], e[1]});
            }
        }

        while (!pq.empty()) {
            auto [s, u, v] = pq.top();
            pq.pop();

            if (find_par(u) == find_par(v)) continue;

            if (s >= mid) {
                // use without upgrade
            } else {
                if (2LL * s < mid) continue;
                if (k == 0) continue;
                k--; // use upgrade
            }

            dsu_union(u, v);
            cnt++;

            if (cnt == n - 1) return true;
        }

        return false;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = INT_MAX, hi = 0;
        for (auto &e : edges) {
            lo = min(lo, e[2]);
            hi = max(hi, e[2] * 2);
        }

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            parents.assign(n, 0);
            rankv.assign(n, 0);
            for (int i = 0; i < n; i++) parents[i] = i;

            if (solve(edges, k, mid, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};