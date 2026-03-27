class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(int i = 0; i < mat.size();i++){
            for(int j = 0; j < mat.at(i).size(); j++){
                if(mat.at(i).at((j+k)%mat.at(i).size()) != mat.at(i).at(j)){
                    return false;
                }
            }
        }
        return true;
    }
};

