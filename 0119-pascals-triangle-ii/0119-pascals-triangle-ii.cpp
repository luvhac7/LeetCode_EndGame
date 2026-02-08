class Solution {
public:
typedef long long ll;
    vector<int> getRow(int a) {
        vector<int>res;res.push_back(1);
        ll x=1;
        for(int i=1;i<=a;i++)
        {
            ll front=x*(a-i+1)/i;
            cout<<front<<" ";
            res.push_back((int)front);
            x=front;
        }
        return res;
    }
};