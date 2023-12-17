class Solution {
public:
    bool valid(int row,int col,int n,vector<string>&mat){
        for(int i=0;i<n;i++){
            if(mat[row][i]=='Q') return false;
        }
        
        for(int i=0;i<n;i++){
            if(mat[i][col]=='Q') return false;
        }
        
        int diff=col-row;
        int sum=row+col;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j-i==diff){    
                    if(mat[i][j]=='Q') return false;
                }
                if(i+j==sum){
                    if(mat[i][j]=='Q') return false;
                }
            }
        }
        
       
        return true;
    }
    
    void queen(int row,int col,int n,vector<string>&mat,vector<vector<string>>&ans){
        
        
        
        if(col>=n){
            ans.push_back(mat);
            return;
        }
        
        
        for(int i=0;i<n;i++){
            if(valid(i,col,n,mat)){
                mat[i][col]='Q';
                queen(row,col+1,n,mat,ans);
                mat[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }

        vector<string>mat(n,s);
        queen(0,0,n,mat,ans);
        return ans;
    }
};