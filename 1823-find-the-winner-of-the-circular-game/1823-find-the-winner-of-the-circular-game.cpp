class Solution {
public:
    
    int findTheWinner(int n, int k) {
        vector<int>vis;
        for(int i=1;i<=n;i++){
            vis.push_back(i);
        }
        int ind=0;
        while(vis.size()>1){
            ind=(ind-1+k)%vis.size();
            vis.erase(vis.begin()+ind);
            
        }
        return vis[0];
    }
};