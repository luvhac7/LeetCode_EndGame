int mod;

struct STNode {
    int value = 1;
    array<int, 6> count{};

    STNode() {}

    STNode(int value) {
        count[this->value = value % mod] = 1;
    }

    auto operator + (STNode const& other) const {
        STNode result = *this;
        result.value = value * other.value % mod;
        for (int i = 0; i < mod; i++)
            result.count[value * i % mod] += other.count[i];
        return result;
    }
};

struct SegmentTree {
    int n;
    vector<STNode> tree;

    SegmentTree(vector<int> const& nums) : n(nums.size()), tree(4 * n) {
        [&] (this auto&& build, int root, int l, int r) -> STNode const& {
            if (l == r) return tree[root] = STNode{nums[l]};

            int mid = midpoint(l, r);
            return tree[root] = build(2 * root + 1, l, mid) + build(2 * root + 2, mid + 1, r);
        } (0, 0, n - 1);
    }

    void update(int i, int value) {
        [&] (this auto&& update, int root, int l, int r) -> void {
            if (l == r) {
                tree[root] = STNode{value};
                return;
            }

            int mid = midpoint(l, r);
            i <= mid ? update(2 * root + 1, l, mid) : update(2 * root + 2, mid + 1, r);
            tree[root] = tree[2 * root + 1] + tree[2 * root + 2];
        } (0, 0, n - 1);
    }

    STNode query(int ql, int qr) {
        return [&] (this auto&& query, int root, int l, int r) -> STNode {
            if (qr < l or r < ql) return STNode{};
            if (ql <= l and r <= qr) return tree[root];

            int mid = midpoint(l, r);
            return query(2 * root + 1, l, mid) + query(2 * root + 2, mid + 1, r);
        } (0, 0, n - 1);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int> const& nums, int k, vector<vector<int>> const& queries) {
        mod = k;
        SegmentTree st(nums);

        vector<int> answer;
        answer.reserve(queries.size());
        for (auto const& q : queries) {            
            st.update(q[0], q[1]);
            int ans = st.query(q[2], nums.size() - 1).count[q[3]];
            answer.push_back(ans);
        }
        return answer;
    }
};