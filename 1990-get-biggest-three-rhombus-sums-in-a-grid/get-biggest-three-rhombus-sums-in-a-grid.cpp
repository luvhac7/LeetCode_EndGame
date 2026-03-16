class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>d1(n,vector<int>(m));
        vector<vector<int>>d2(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int row = 0;
            int col = j;
            d1[row][col] = grid[row][col]; 
            row++;
            col--;
            while(col>=0 && row<n){
                d1[row][col] = d1[row-1][col+1] + grid[row][col];
                row++;
                col--;
            }
        }
        for(int i=1;i<n;i++){
            int row = i;
            int col = m-1;
            d1[row][col] = grid[row][col];
            row++;
            col--;
            while(col>=0 && row<n){
                d1[row][col] = d1[row-1][col+1] + grid[row][col];
                row++;
                col--;
            }
        }

        for(int j=0;j<m;j++){
            int row = 0;
            int col = j;
            d2[row][col] = grid[row][col];
            row++;
            col++;
            while(col<m && row<n){
                d2[row][col] = d2[row-1][col-1] + grid[row][col];
                row++;
                col++;
            }
        }
        for(int i=1;i<n;i++){
            int row = i;
            int col = 0;
            d2[row][col] = grid[row][col];
            row++;
            col++;
            while(col<m && row<n){
                d2[row][col] = d2[row-1][col-1] + grid[row][col];
                row++;
                col++;
            }
        }

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ind1 = i;
                int ind2 = j;

                int side = 1;
                while(true){
                    int p1c = ind2 + side - 1;
                    int p2c = ind2 - side + 1;
                    int p1r, p2r;
                    p1r = p2r = ind1 + side - 1;

                    int p3c = ind2;
                    int p3r = p2r + side - 1;

                    bool s1 = (p1c<m) && (p2c<m) && (p3c<m);
                    bool s2 = (p1r<n) && (p2r<n) && (p3r<n);
                    bool s3 = (p1c>=0) && (p2c>=0) && (p3c>=0);
                    bool s4 = (p1r>=0) && (p2r>=0) && (p3r>=0);

                    if(s1 && s2 && s3 && s4){
                        int sum = 0;
                        if(side==1){
                            sum = grid[ind1][ind2];
                        }
                        else{
                            int edge1 = d2[p1r][p1c] - d2[ind1][ind2];
                            int edge2 = d1[p2r][p2c] - d1[ind1][ind2];
                            int edge3 = d2[p3r][p3c] - d2[p2r][p2c];
                            int edge4 = d1[p3r][p3c] - d1[p1r][p1c];
                            
                            sum = edge1 + edge2 + edge3 + edge4 + grid[ind1][ind2] - grid[p3r][p3c];
                        }

                        bool found = false;
                        vector<int> temp; 
                        while(!pq.empty()){
                            if(pq.top() == sum) found = true;
                            temp.push_back(pq.top());
                            pq.pop();
                        }
                        for(int x : temp) pq.push(x);

                        if (!found) {
                            if(pq.size() < 3) {
                                pq.push(sum);
                            }
                            else if (pq.top() < sum) {
                                pq.pop();
                                pq.push(sum);
                            }
                        }
                        side++; 
                    }
                    else{
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};