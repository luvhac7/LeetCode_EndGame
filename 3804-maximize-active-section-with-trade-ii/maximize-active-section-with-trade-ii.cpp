struct SegTree {
    int n; vector<int> tree;
    SegTree(const vector<int>& a) : n(a.size()), tree(4 * max(1, n), 0) { if(n) build(1, 0, n - 1, a); }
    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) { tree[node] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build((node << 1) | 1, mid + 1, r, a);
        tree[node] = max(tree[node << 1], tree[(node << 1) | 1]);
    }
    int query(int node, int st, int en, int l, int r) {
        if (l <= st && en <= r) return tree[node];
        int mid = (st + en) >> 1, res = 0;
        if (mid >= l) res = max(res, query(node << 1, st, mid, l, r));
        if (r > mid) res = max(res, query((node << 1) | 1, mid + 1, en, l, r));
        return res;
    }
    int query(int l, int r) { return (l > r || n == 0) ? 0 : query(1, 0, n - 1, l, r); }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n = s.size(), cnt1 = count(s.begin(), s.end(), '1');
        vector<int> zb, zl, zr, ans;
        
        for (int idx = 0; idx < n; ) {
            int r = idx;
            while (r < n && s[idx] == s[r]) r++;
            if (s[idx] == '0') {
                zb.push_back(r - idx);
                zl.push_back(idx);
                zr.push_back(r - 1);
            }
            idx = r;
        }
        
        int m = zb.size();
        if (m <= 1) return vector<int>(q.size(), cnt1);
        
        vector<int> nums(m - 1);
        for (int i = 0; i < m - 1; i++) nums[i] = zb[i] + zb[i + 1];
        SegTree st(nums);
        
        for (auto& qr : q) {
            int l = qr[0], r = qr[1];
            int lidx = lower_bound(zr.begin(), zr.end(), l) - zr.begin();
            int ridx = upper_bound(zl.begin(), zl.end(), r) - zl.begin() - 1;
            
            if (lidx >= m || ridx < 0 || lidx >= ridx) { ans.push_back(cnt1); continue; }
            
            int leftLen = zr[lidx] - max(zl[lidx], l) + 1;
            int rightLen = min(r, zr[ridx]) - zl[ridx] + 1;
            
            if (lidx + 1 == ridx) { ans.push_back(cnt1 + leftLen + rightLen); continue; }
            
            int leftContri = leftLen + zb[lidx + 1];
            int rightContri = rightLen + zb[ridx - 1];
            int middleContri = st.query(lidx + 1, ridx - 2);
            ans.push_back(cnt1 + max({leftContri, rightContri, middleContri}));
        }
        return ans;
    }
};
