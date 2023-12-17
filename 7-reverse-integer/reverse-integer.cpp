class Solution {
public:
    int reverse(int x) {
        int ans=0;
        bool sign=(x>0);
        x=abs(x);
        while(x>0){
            if((long)ans*10>=INT_MAX) return 0;
            ans= (ans*10) + (x%10);
            x/=10;
        }

        if(!sign) return -ans;
        return ans;
    }
};