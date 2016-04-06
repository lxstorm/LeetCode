class Solution {
public:
    bool isPalindrome(int x) {
        int rx = reverse(x);
        return rx == x;
    }
    int reverse(int x){
        long long res = 0;
        int sgn = 1;
        if(x < 0)
            sgn = -1;
        while(x != 0){
            res = res * 10 + x % 10;
            x = x / 10;
        }
        res = res * sgn;
        if(res > INT_MAX || res < INT_MIN)
            return 0;
        return res;
    }
};
