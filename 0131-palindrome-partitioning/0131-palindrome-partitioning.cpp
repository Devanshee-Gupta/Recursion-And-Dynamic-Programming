class Solution {
public:
    bool check(int i,string &s){
        if(i>=s.length()/2){
            return 1;
        }
        
        if(s[i]!=s[s.length()-i-1]) return 0;
        
        return check(i+1,s);
    }
    
    void f(string temp, string s, vector<string>&ds,vector<vector<string>>&ans){
        
        if(s.length()==0){
            ans.push_back(ds);
            return;
        }
        string copys=s;
        for(int i=0;i<s.length();i++){
            temp=s.substr(0,i+1);
            s=s.substr(i+1,string::npos);
            if(check(0,temp)){
                ds.push_back(temp);
                f(temp,s,ds,ans);
                ds.pop_back();
            }
            s=copys;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        
        f("",s,ds,ans);
        
        return ans;
    }
};