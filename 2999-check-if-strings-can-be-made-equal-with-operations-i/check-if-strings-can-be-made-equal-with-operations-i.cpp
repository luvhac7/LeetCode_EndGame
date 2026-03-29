class Solution {
public:
    bool canBeEqual(string s1, string s2) {
      string a="";a+=s1[0];a+=s1[2];
      string b="";b+=s2[0];b+=s2[2];
      string c="";c+=s1[1];c+=s1[3];
      string d="";d+=s2[1];d+=s2[3];
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      sort(c.begin(),c.end());
      sort(d.begin(),d.end());
    if(a!=b) return false;
    if(c!=d) return false;
return true;
    }
};
