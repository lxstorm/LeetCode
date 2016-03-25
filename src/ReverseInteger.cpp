class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int sgn = 1;
        // 1 denote the positive , 0 negative
        if (x >= 0){
            sgn = 1;
        }
        else{
            sgn = 0;
            x = -x;
        }
        while(x / 10 > 0){
            res = res * 10 + x  % 10;
            x = x / 10;
        }
        res = res * 10 + x  % 10;
        if(res > 2147483647 )
            return 0;
        sgn == 1 ? : res = -res;
        return res;
    }
};
