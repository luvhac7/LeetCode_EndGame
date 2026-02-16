class Solution {
public:
    int reverseBits(int n) {
    bitset<32>bin(n);
    string x=bin.to_string();
    reverse(x.begin(),x.end());
    return (int)bitset<32>(x).to_ulong();
    }
};