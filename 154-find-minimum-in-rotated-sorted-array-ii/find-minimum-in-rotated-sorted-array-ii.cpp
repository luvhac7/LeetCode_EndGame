class Solution {
public:
    int findMin(vector<int>& a) {
        int s = 0;
        int e = a.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (a[mid] > a[e]) {
                s = mid + 1;
            }
            else if (a[mid] < a[e]) {
                e = mid;
            }
            else {
                e--;
            }
        }
        return a[s];
    }
};