struct Node {
    short mn, mx, lz;
    Node() : mn(SHRT_MAX), mx(SHRT_MIN), lz(0) {}
    Node(int x) : mn(x), mx(x), lz(0) {}
};

struct SegTree {
    vector<Node> t;
    int n;
    SegTree(vector<int>& a) {
        n = a.size();
        t.assign(n << 2, Node());
        build(1, 0, n - 1, a);
    }
    void pull(int i) {
        t[i].mn = min(t[i << 1].mn, t[i << 1 | 1].mn);
        t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    }
    void build(int i, int l, int r, vector<int>& a) {
        if (l == r) {
            t[i] = Node(a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(i << 1, l, m, a);
        build(i << 1 | 1, m + 1, r, a);
        pull(i);
    }
    void push(int i, int l, int r) {
        if (!t[i].lz)
            return;
        t[i].mn += t[i].lz;
        t[i].mx += t[i].lz;
        if (l < r) {
            t[i << 1].lz += t[i].lz;
            t[i << 1 | 1].lz += t[i].lz;
        }
        t[i].lz = 0;
    }
    void upd(int s, int e, int i, int l, int r, int v) {
        push(i, l, r);
        if (r < s || l > e)
            return;
        if (l >= s && r <= e) {
            t[i].lz += v;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        upd(s, e, i << 1, l, m, v);
        upd(s, e, i << 1 | 1, m + 1, r, v);
        pull(i);
    }
    int find0(int i, int l, int r) {
        push(i, l, r);
        if (t[i].mn > 0 || t[i].mx < 0)
            return -1;
        if (l == r)
            return l;
        int m = (l + r) >> 1;
        int x = find0(i << 1 | 1, m + 1, r);
        return x != -1 ? x : find0(i << 1, l, m);
    }
};

constexpr int N = 1e5 + 1;
bitset<N> seen;

class Solution {
public:
    static int brute(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int l = 0; l < n; l++) {
            if (l > n - ans)
                break;
            int d = 0;
            for (int r = l; r < n; r++) {
                if (!seen[a[r]]) {
                    d += (a[r] & 1) ? -1 : 1;
                    seen[a[r]] = 1;
                }
                if (!d)
                    ans = max(ans, r - l + 1);
            }
            for (int i = l; i < n; i++)
                seen[a[i]] = 0;
        }
        return ans;
    }

    static int longestBalanced(vector<int>& a) {
        int n = a.size();
        if (n <= 2000)
            return brute(a);

        int M = *max_element(a.begin(), a.end());
        vector<int> last(M + 1, n), nxt(n, n);

        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last[a[i]];
            last[a[i]] = i;
        }

        vector<int> pref(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[a[i]]) {
                s += (a[i] & 1) ? 1 : -1;
                seen[a[i]] = 1;
            }
            pref[i] = s;
        }
        for (int i = 0; i < n; i++)
            seen[a[i]] = 0;

        SegTree st(pref);
        int ans = st.find0(1, 0, n - 1) + 1;

        for (int i = 0; i < n - 1; i++) {
            int r = nxt[i] - 1;
            if (i + 1 <= r) {
                int v = (a[i] & 1) ? -1 : 1;
                st.upd(i + 1, r, 1, 0, n - 1, v);
            }
            if (i + ans + 1 < n) {
                int x = st.find0(1, 0, n - 1);
                if (x != -1)
                    ans = max(ans, x - i);
            }
        }
        return ans;
    }
};