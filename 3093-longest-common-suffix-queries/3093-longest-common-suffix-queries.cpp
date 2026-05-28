// class Solution {
// public:
//     class TrieNode{
//         public:
//         // TrieNode*children[26];
//         unordered_map<char,TrieNode*>children;
//         int minLength;
//         int minIndex;
//         TrieNode(){
//             minLength=1e6;
//             minIndex=-1;
//         }
//     };
//     void insert(TrieNode*root,string& word,int& originalIndex){
//         TrieNode*curr=root;
//         int wordLen=word.length();
//         if(wordLen<curr->minLength){
//             curr->minLength=wordLen;
//             curr->minIndex=originalIndex;
//         }
//         for(char ch:word){
//             // int indx=ch-'a';
//         //    if(curr->children[indx]==nullptr){/
//             if(curr->children.find(ch)==curr->children.end()){
//                 curr->children[ch]=new TrieNode();
//             }
//             curr=curr->children[ch];
//             if(wordLen<curr->minLength){
//             curr->minLength=wordLen;
//             curr->minIndex=originalIndex;
//             }
//         }
//     }
//     int searchLongestSuffix(TrieNode*root, string&query){
//         TrieNode*curr=root;
//         int bestIndex=root->minIndex;
//         for(char ch:query){
//             // int indx=ch-'a';
//             // if(curr->children[indx]!=nullptr){
//             if(curr->children.find(ch)!=curr->children.end()){
//                 curr=curr->children[ch];
//                 bestIndex=curr->minIndex;
//             }else{
//                 break;
//             }
//         }
//         return bestIndex;
//     }
//     vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//         TrieNode*root=new TrieNode();
//         for(int i=0;i<wordsContainer.size();i++){
//             string word=wordsContainer[i];
//             reverse(word.begin(),word.end());
//             insert(root,word,i);
//         }
//         vector<int>ans;
//         for(string query:wordsQuery){
//             reverse(query.begin(),query.end());
//             int best=searchLongestSuffix(root,query);
//             ans.push_back(best);
//         }
//         return ans;
//     }
// };

class Solution{
    public:
        static const int maxNode=500005;
        int children[maxNode][26];
        int minLength[maxNode];
        int minIndex[maxNode];
        int nodeCount;
        void initNode(int i){
            minLength[i]=1e9;
            minIndex[i]=-1;
            for(int j=0;j<26;j++){
                children[i][j]=-1;
            }
        }
        void insert(string& word,int originalIndex){
            int curr=0;
            int wordLen=word.length();
            if(wordLen<minLength[curr]){
                minLength[curr]=wordLen;
                minIndex[curr]=originalIndex;
            }
            for(char ch:word){
                int indx=ch-'a';
                if(children[curr][indx]==-1){
                    nodeCount++;
                    initNode(nodeCount);
                    children[curr][indx]=nodeCount;
                }
                curr=children[curr][indx];
                if(wordLen<minLength[curr]){
                    minLength[curr]=wordLen;
                    minIndex[curr]=originalIndex;
                }
            }
        }
        int searchLongestSuffix(string &query){
            int curr=0;
            int bestIndex=minIndex[0];
            for(char ch:query){
                int indx=ch-'a';
                if(children[curr][indx]!=-1){
                    curr=children[curr][indx];
                    bestIndex=minIndex[curr];
                }else{
                    break;
                }
            }
            return bestIndex;
        }
        vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
            nodeCount=0;
            initNode(0);
            for(int i=0;i<wordsContainer.size();i++){
                string word=wordsContainer[i];
                reverse(word.begin(),word.end());
                insert(word,i);
            }
            vector<int>ans;
            for(string q:wordsQuery){
                reverse(q.begin(),q.end());
                int best=searchLongestSuffix(q);
                ans.push_back(best);
            }
            return ans;
        }
};