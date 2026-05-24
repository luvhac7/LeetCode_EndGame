class Solution {
public:
    int maxJumps(vector<int>& arr, int dist) {

        int n = arr.size();
        int maxe = 1;
        vector<int> reach(n,0);

        vector<int> v(n);
        iota(v.begin(), v.end() , 0);
        sort(v.begin(),v.end(), [&](const int &a, const int &b)
        {
            return arr[a] < arr[b];
            
        });

        for (int i = 0; i < n; i++) {

            queue<int> q;
            vector<int> vis(n, 0);
            q.push(v[i]);

            vis[v[i]]=1;
            reach[v[i]]=1;

            int d = 1;

            while (!q.empty()) {

                int k = q.size();
                reach[v[i]]= max(reach[v[i]], d);

                for (int z = 0; z < k; z++) {

                    int p = q.front();
                    q.pop();

                    for (int j = p+1; j < n && j <= p + dist; j++) {

                        if(arr[j]>= arr[p]) break;
                        if ( !vis[j]) {
                            if( reach[j]!=-1 )
                            {
                                vis[j]=1;
                                reach[v[i]]= max(reach[v[i]],d+reach[j]);
                                // cout << i << " " << j <<" "<< reach[i] <<endl; 

                            }
                            else {
                                q.push(j);
                            }

                        }
                    }
                    for (int j = p-1; j >= 0 && j >= p - dist; j--) {
                        {
                            if(arr[j]>= arr[p]) break;
                            if ( !vis[j]) {

                                if(reach[j]!=-1 )
                                {
                                    vis[j]=1;
                                    reach[v[i]]= max( reach[v[i]],d+ reach[j]);
                                    // cout << v[i] << " " << j<< " " <<reach[j] <<endl;

                                } 
                                else  {
                                    q.push(j);
                                }
                            }
                        }
                    }
                }
                d++;
            }
        }

        for (int i = 0; i < n; i++) {
            maxe = max(maxe, reach[i]);
        }
        // for(auto &x : reach)
        // {
        //     cout << x <<" ";
        // }
        return maxe;
    }
};