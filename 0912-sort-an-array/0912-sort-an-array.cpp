class Solution {
public:
    void mergesort(int l,int r,vector<int>&nums){
        
     
        if (l >= r) {
            return;
        }
        
        int mid=(l+r)/2;
        vector<int>temp;
        
        mergesort(l,mid,nums);
        mergesort(mid+1,r,nums);
        
        int i=l,j=mid+1;
        
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        
        for(int i=0;i<temp.size();i++){
            nums[l+i]=temp[i];
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};