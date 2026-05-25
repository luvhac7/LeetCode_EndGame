class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // if any zero is invalid , move ahead , dont add it to the zero set 
        vector<int> setz;
        setz.push_back(0);
        int n =s.size();
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
            int left =(i-maxJump);
            int right=(i-minJump);
            if(left<0 && right<0) continue;
            else if(left<0 && right>=0){
                left=0;
            }
            // we have the left and right  
            // get first index where el>=left , and found in set 
            int low =0;
            int high =setz.size()-1;
            while(low<=high){
                int mid =low+(high-low)/2;
                if(setz[mid]>=left){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }

            // if(low<setz.size()) cout<<"low index "<<low<<endl;

            // check if low is valid 
            // check if low is valid and index 
            // cout<<"left and right "<<left<<" "<<right<<endl;
            if(low<setz.size()){
                // cout<<setz[low]<<" "<<endl;
                if(setz[low]<=right && setz[low]>=left){
                    // cout<<"valid "<<i<<endl;
                    setz.push_back(i);
                }
            }
            }
        }

        // for(int el:setz) cout<<el<<" ";
        // cout<<endl;
        // check if the last index is n-1 
        return setz[setz.size()-1]==n-1;
    }
};