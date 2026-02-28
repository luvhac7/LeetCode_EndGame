class Solution {
public:
int x[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string p[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int a) {
        string res;
        for(int i=0;i<13;i++)
        {
            while(a>=x[i])
            {
                res.append(p[i]);
                a-=x[i];
            }
        }
        return res; 
    }
};