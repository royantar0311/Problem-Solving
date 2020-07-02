class Solution {
public:
    int arrangeCoins(int n) {
        long long ans = 0 ;
        for(long long i=1;;i++){
            ans = i*1LL*(i+1)/2;
            if(ans>n)return i-1;
        }
    }
};