class Solution {
public:
    vector<int> mergesort(int l,int r,vector<int>&nums){
        
     
        if (l >= r) {
            return vector<int>(nums.begin() + l, nums.begin()+r+1);
        }
        
        int mid=(l+r)/2;
        vector<int>left,right,temp;
        
        left = mergesort(l,mid,nums);
        right = mergesort(mid+1,r,nums);
        
        int i=0,j=0;
        
        while(i<left.size() && j<right.size()){
            if(left[i]<=right[j]){
                temp.push_back(left[i]);
                i++;
            }
            else{
                temp.push_back(right[j]);
                j++;
            }
        }
        
        while(i<left.size()){
            temp.push_back(left[i]);
            i++;
        }
        while(j<right.size()){
            temp.push_back(right[j]);
            j++;
        }
        
        return temp;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        return mergesort(0,nums.size()-1,nums);
    }
};