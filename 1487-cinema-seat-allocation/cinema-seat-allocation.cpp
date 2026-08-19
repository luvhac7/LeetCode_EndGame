class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> umap;
        for(auto it: reservedSeats) {
            umap[it[0]].insert(it[1]);
        }
        int res = (n - umap.size()) * 2;
        for(auto row: umap) {
            bool left = !row.second.contains(2) && !row.second.contains(3) && !row.second.contains(4) && !row.second.contains(5);
            bool right = !row.second.contains(6) && !row.second.contains(7) && !row.second.contains(8) && !row.second.contains(9);
            bool centre = !row.second.contains(4) && !row.second.contains(5) && !row.second.contains(6) && !row.second.contains(7);
            if(left && right)
            res+=2;
            else if(left || right || centre)
            res++;
        }
        return res;
    }
};