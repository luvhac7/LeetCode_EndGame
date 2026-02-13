class Solution{
public:
typedef long long ll;

int longestBalanced(string s){
int x=calc1(s);
int y=max({calc2(s,'a','b'),calc2(s,'b','c'),calc2(s,'a','c')});
int z=calc3(s);
return max({x,y,z});
}
private:
int calc1(const string&s){
int res=0;
for(int i=0;i<s.size();){
int j=i;
while(j<s.size()&&s[j]==s[i])j++;
res=max(res,j-i);
i=j;
}
return res;
}
int calc2(const string&s,char a,char b){
int res=0,n=s.size(),i=0;
while(i<n){
while(i<n&&s[i]!=a&&s[i]!=b)i++;
unordered_map<int,int>mp;
mp[0]=i-1;
int diff=0;
while(i<n&&(s[i]==a||s[i]==b)){
diff+=(s[i]==a?1:-1);
if(mp.count(diff))res=max(res,i-mp[diff]);
else mp[diff]=i;
i++;
}
}
return res;
}
ll key(int x,int y){
return((ll)(x+100000)<<20)|(y+100000);
}
int calc3(const string&s){
unordered_map<ll,int>mp;
mp[key(0,0)]=-1;
int cnt[3]={0},res=0;
for(int i=0;i<s.size();i++){
cnt[s[i]-'a']++;
int x=cnt[0]-cnt[1];
int y=cnt[1]-cnt[2];
ll k=key(x,y);
if(mp.count(k))res=max(res,i-mp[k]);
else mp[k]=i;
}
return res;
}
};
