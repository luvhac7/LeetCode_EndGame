class Solution {
    int n=3,N=9;
    int r[9][10]={},c[9][10]={},bx[9][10]={};
    vector<vector<char>>*bp;
    bool sol=false;
    bool can(int d,int row,int col)
    {
        int id=(row/n)*n+col/n;
        return row[r][d]+col[c][d]+bx[id][d]==0;
    }
    void place(int d,int row,int col)
    {
        int id=(row/n)*n+col/n;
        row[r][d]++;
        col[c][d]++;
        bx[id][d]++;
        (*bp)[row][col]=d+'0';
    }
    void remove(int d,int row,int col)
    {
        int id=(row/n)*n+col/n;
        row[r][d]--;
        col[c][d]--;
        bx[id][d]--;
        (*bp)[row][col]='.';

    }
    void placed(int row,int col)

    {
        if(row==N-1 && col==N-1) sol=true;
        else if(col==N-1) back(row+1,0);
        else back(row,col+1);
    }
    void back(int row,int col)
    {
        if((*bp)[row][col]=='.'){
            for(int d=1;d<=9;d++)
            {
                if(can(d,row,col)){
                    place(d,row,col);
                    placed(row,col);
                    if(!sol) remove(d,row,col);
                }
            }
        }
            else placed(row,col);
        
    }
public:
    void solveSudoku(vector<vector<char>>& b) {
        bp=&b;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(b[i][j]!='.') place(b[i][j]-'0',i,j);
            }
            
        }
        back(0,0);
    }
};