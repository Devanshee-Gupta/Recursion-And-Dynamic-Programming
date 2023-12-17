class Solution {
public:
    bool  f(int row,int col,int i,vector<vector<char>>& board, string word){
        
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
        
        if(i==word.length()){
            return true;
        }
        if(board[row][col]=='0' or board[row][col]!=word[i]) return false;
        
        i++;
        char temp=board[row][col];
        board[row][col]='0';
        bool left=f(row,col-1,i,board,word);
        if(left) return true;

        bool rgt=f(row,col+1,i,board,word);
        if(rgt) return true;

        bool up=f(row-1,col,i,board,word);
        if(up) return true;

        bool down=f(row+1,col,i,board,word);
        if(down) return true;

        board[row][col]=temp;
        
        
        return false;

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==1 && word.length()==1 && board[0][0]==word[0]) return 1; 
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(f(i,j,0,board,word)) return true;
            }
        }

        return false;
        
    }
};