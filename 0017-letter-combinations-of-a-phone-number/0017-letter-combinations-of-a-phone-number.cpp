class Solution {
public:
    void f(int ind,string &digits,vector<string>&code,string &temp,vector<string>&ans){
        if(ind>=digits.length()){
            ans.push_back(temp);
            return;
        }
        int digit=(digits[ind] - '0');
        for(int i=0;i<code[digit].length();i++){
            temp+=code[digit][i];
            f(ind+1,digits,code,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>code={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp="";
        if(digits=="") return ans;
        
        f(0,digits,code,temp,ans);
        return ans;
    }
};