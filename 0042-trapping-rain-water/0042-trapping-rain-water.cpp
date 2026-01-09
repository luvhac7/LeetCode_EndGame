class Solution {
public:
    int trap(vector<int>& h) {
        int l=0;
        int r=h.size()-1;
        int lmax=h[l];
        int rmax=h[r];
        int w=0;
        while(l<r)
        {
        if(lmax<rmax){
            l++;
            lmax=max(lmax,h[l]);
            w+=lmax-h[l];
        }
        else{
            r--;
            rmax=max(rmax,h[r]);
            w+=rmax-h[r];
        }
    }
    return w;
    }
    
};