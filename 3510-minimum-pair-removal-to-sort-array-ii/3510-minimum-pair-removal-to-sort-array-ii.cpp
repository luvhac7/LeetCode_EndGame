class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& a) {
        int n = a.size();

        // values as long long
        vector<ll> v(a.begin(), a.end());

        // doubly linked list using indices
        vector<int> nxt(n), prv(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = i + 1;
            prv[i] = i - 1;
        }

        // {pairSum, index}
        set<pair<ll,int>> st;

        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (v[i] > v[i + 1]) bad++;
            st.insert({v[i] + v[i + 1], i});
        }

        int ops = 0;

        while (bad > 0) {
            auto [sum, i] = *st.begin();
            st.erase(st.begin());

            int j = nxt[i];        // next
            int pi = prv[i];       // prev
            int nj = nxt[j];       // next of next

            // remove old bad pairs
            if (v[i] > v[j]) bad--;

            if (pi >= 0) {
                if (v[pi] > v[i]) bad--;
                if (v[pi] > v[i] + v[j]) bad++;
                st.erase({v[pi] + v[i], pi});
            }

            if (nj < n) {
                if (v[j] > v[nj]) bad--;
                if (v[i] + v[j] > v[nj]) bad++;
                st.erase({v[j] + v[nj], j});
            }

            // merge i and j
            v[i] += v[j];
            nxt[i] = nj;
            if (nj < n) prv[nj] = i;

            // add new pairs
            if (pi >= 0) st.insert({v[pi] + v[i], pi});
            if (nj < n) st.insert({v[i] + v[nj], i});

            ops++;
        }
        return ops;
    }
};
