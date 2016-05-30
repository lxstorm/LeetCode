class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        //because the input is int, the overflow only happens when the
        //1. divisor is 0;
        //2. diviend is INT_MIN and divisor is -1, because of |INT_MIN| =
        //  |INT_MAX| + 1
        if(!divisor || (dividend == INT_MIN) && divisor == -1)
            return INT_MAX;
        int sgn = (dividend < 0) ^ (divisor < 0) ? -1: 1;
        //use labs to prevent the abs of INT_MIN overflow, the input is
        //legal so we need to use long type to store it;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        // a example: 22 = 3 * 2^2 + 3* 2^1 + 4;
        while(dvd >= dvs){
            long temp = dvs;
            int cnt = 1;
            while(dvd >= temp<<1){
                temp = temp << 1;
                cnt = cnt << 1;
            }
            dvd -= temp;
            ans += cnt;
        }
        return sgn * ans;
    }
};
