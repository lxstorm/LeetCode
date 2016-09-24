class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int l = 0;
        int r = INT_MAX;
        while(l + 1 != r){
            int mid = l + (r - l) / 2;
            if(mid < x / mid)
                l = mid;
            else if(mid > x / mid)
                r = mid;
            else
                return mid;
        }
        return l;
    }
};
