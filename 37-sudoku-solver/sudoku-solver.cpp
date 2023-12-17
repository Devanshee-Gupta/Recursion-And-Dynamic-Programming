class Solution {
public:
    bool valid(vector<vector<char>>& board,int row,int col,int num){
        char x=num+'0';
        for(int j=0;j<9;j++){
            if(board[row][j]==x) return false;
        }
        
        for(int j=0;j<9;j++){
            if(board[j][col]==x) return false;
        }
        
        int boxi=(row/3)*3,boxj=(col/3)*3;
        for(int i=boxi;i<boxi+3;i++){
            for(int j=boxj;j<boxj+3;j++){
                if(board[i][j]==x) return false;
            }
        }
        
        return true;
    }

    bool f(vector<vector<char>>& board,int row,int col){
   
        if(row==8 and col==9) return true;
        
        if(row>=9) return false;
        
        if(col>=9){
            col=0;
            row++;
        }
        
        if(board[row][col]!='.'){
            return f(board,row,col+1);
        }
            
        for(int j=1;j<=9;j++){
        
            if(valid(board,row,col,j)){
                board[row][col]='0'+j;
                bool ans= f(board,row,col+1);
                if(ans){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};