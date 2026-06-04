class Solution {
public:
string f(string a,string b)
{
    int x=0,y=0;
    int xcnt[10]={},ycnt[10]={};
    for(int i=0;i<a.size();i++)
    {
        int gd=b[i]-'0';
        int sd=a[i]-'0';
        if(sd==gd) x++;
        else{
            xcnt[sd]++;
            ycnt[gd]++;
        }
    }
    for(int i=0;i<10;i++)
    {
        y+=min(xcnt[i],ycnt[i]);
    }
    return to_string(x)+"A"+to_string(y)+"B";
}

    string getHint(string a, string b) {
        return f(a,b);
    }
};