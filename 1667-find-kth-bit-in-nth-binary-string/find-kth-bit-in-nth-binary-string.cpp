class Solution {
public:
    string generate(int n){
        if(n==1) return "0";

        string s = generate(n-1);
        string rev="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0') rev+="1";
            else rev+="0";
        }
        return s+"1"+rev;

    }
    char findKthBit(int n, int k) {
        string s=generate(n);
        return s[k-1];
    }
};