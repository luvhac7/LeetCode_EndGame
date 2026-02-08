class Solution {
public:
void rotate(vector<int>&a,int st,int end)
{
    int e=a[end];
    for(int i=end;i>st;i--)
    {
        a[i]=a[i-1];
    }
    a[st]=e;
}
    vector<int> rearrangeArray(vector<int>& a) {
        int n=a.size();
        ///----------------Brute-Force-------------------------O(n2)
//         for(int i=0;i<n;i++)
//         {
//             if(i%2==1 && a[i]>=0)
//             {
//                 for(int j=i+1;j<n;j++)
//                 {
//                     if(a[j]<0)
//                     {
//                         rotate(a,i,j);break;
//                     }
//                 }
//             }
//             else if(a[i]<0 && i%2==0)
//             {
//                 for(int j=i+1;j<n;j++)
//                 {
//                     if(a[j]>=0)
//                     {
//                         rotate(a,i,j);break;
//                     }
//                 }
//             }
//         }
// return a;


//--------------------------Optimal----------------------------O(N)

vector<int>res(n);
int pos=0,neg=1;
for(int i:a)
{
    if(i>=0)
    {
        res[pos]=i;pos+=2;
    }
    else{
        res[neg]=i;neg+=2;
    }
}
    return res;
}




    
};