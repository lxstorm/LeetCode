class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int rx = reverse(x);
        return rx == x;
    }
    int reverse(int x){
        long long res = 0;
        while(x != 0){
            res = res * 10 + x % 10;
            x = x / 10;
        }
        if(res > INT_MAX)
            return 0;
        return res;
    }
};
