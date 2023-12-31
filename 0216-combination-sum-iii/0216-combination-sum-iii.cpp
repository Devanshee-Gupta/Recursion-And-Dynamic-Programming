class Solution {
public:
    void rec(int ind,int n,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int k,int sum){
        
        if(ds.size()==k){
            if(sum==0) ans.push_back(ds);
            return;
        }
        if(ds.size()>k) return;
        
        
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            
            if(sum<nums[i]) break;
            
            ds.push_back(nums[i]);
            rec(i+1,n,nums,ds,ans,k,sum-nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++) nums.push_back(i);
        vector<vector<int>>ans;
        vector<int>ds;
        rec(0,9,nums,ds,ans,k,n);
        
        return ans;
    }
};