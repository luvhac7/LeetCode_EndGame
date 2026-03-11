class Solution {
public:
    int bitwiseComplement(int n) {
      return n != 0 ? n^(int)pow(2, (int)(log2(n)+1) )-1 : 1;  
    }
};