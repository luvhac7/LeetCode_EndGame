class Solution {
public:
vector<string>res;
void f(int n,int k,string temp,int cost,char prev)
{
    if(temp.size()>n||cost>k) return ;
    if(temp.size()==n){res.push_back(temp);return;}
    if(prev!='1'){
        f(n,k,temp+'1',cost+temp.size(),'1');
    }
    f(n,k,temp+'0',cost,'0');
}
    vector<string> generateValidStrings(int n, int k) {
        f(n,k,"",0,'-');
        return res;
    }
};