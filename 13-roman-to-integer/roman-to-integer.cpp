class Solution {
public:
int solve(string s)
{
    int v['X'+1],sum=0;
    v['I']=1;v['V']=5;
    v['X']=10;v['L']=50;
    v['C']=100;v['D']=500;
    v['M']=1000;
    for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&v[s[i]]<v[s[i+1]]) sum-=v[s[i]];
            else sum+=v[s[i]];
    }
    return sum;
}
    int romanToInt(string s) {
    //     int x=0;
    //     for(char c:s)
    //     {
    //         if(c=='I') x+=1;
    //         if(c=='V') x+=5;
    //         if(c=='X') x+=10;
    //         if(c=='L') x+=50;
    //         if(c=='C') x+=100;
    //         if(c=='D') x+=500;
    //         if(c=='M') x+=1000;
    //     }
    // for(int i=1;i<s.size();i++)
    // {
    // if(s[i]=='V' || s[i]=='X'||s[i]=='L'||s[i]=='C'||s[i]=='D'||s[i]=='M'){
    //     if(s[i-1]=='I') x-=222;
    // }
    // }
    // cout<<2216-1994<<" ";
    return solve(s);
    }
};