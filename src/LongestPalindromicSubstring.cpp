class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int ml = 0;
        int mr = 0;
        string maxString;
        int i = 0;
        int l = 0;
        int r = 0;
        while(i < 2 * s.size()){
            if(i % 2 == 0){
            l = r = i/2;
            }
            else{
            l = (i - 1) / 2;
            r = (i + 1) / 2;
            }

            while(l >= 0 && r < s.size()){
                if(s[l] != s[r])
                    break;
                --l;
                ++r;
            }
            l = l + 1;
            r = r - 1;
            if(maxLen < r - l + 1){

                maxLen = r - l + 1;
                ml = l;
                mr = r;
            }
            ++i;
        }
        return s.substr(ml, maxLen);
    }
};
