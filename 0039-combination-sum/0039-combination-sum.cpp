class Solution {
public:
    void rec(int ind,int n,vector<vector<int>>&ans,vector<int>&arr,vector<int>&temp,int target)
    {
        
        if(ind==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target>=arr[ind]){
            temp.push_back(arr[ind]);
            rec(ind,n,ans,arr,temp,target-arr[ind]);
            temp.pop_back();
        }
        rec(ind+1,n,ans,arr,temp,target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(0,candidates.size(),ans,candidates,temp,target);
        return ans;
        
    }
};