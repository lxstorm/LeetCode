class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int sgn = 1;
        if (x < 0){
            sgn = 0;
            x = -x;
        }
        while(x  > 0){
            res = res * 10 + x  % 10;
            x = x / 10;
        }
        sgn == 1 ? : res = -res;
        cout<<res<<endl;
        if(res >= INT_MAX || res <=INT_MIN)
            return 0;
        return res;
    }
};
