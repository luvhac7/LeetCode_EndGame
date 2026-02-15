class Solution {
public:
string solve(string a,string b)
{
	string res;
	int ia=a.size()-1;
	int ib=b.size()-1;
	int car=0;
	while(ia>=0||ib>=0||car)
	{
		if(ia>=0)
		{
			car+=a[ia--]-'0';
		}
		if(ib>=0)
		{
			car+=b[ib--]-'0';
		}
	res.push_back((car%2)+'0');
	car/=2;
	}
	reverse(res.begin(),res.end());
	return res;
}
    string addBinary(string a, string b) {
        return solve(a,b);
    }
};