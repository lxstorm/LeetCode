/* first AC solution
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
*/
/*
    second AC version
    try to seperate the string to some palindromic parts
    if we skip the duplicate characters,then the center can directly skip the
    palindromic part to find the next palindromic part;

*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        int maxLen = 0;
        int ml = 0;
        int start = 0;
        while(start < s.size() && start < (s.size() - maxLen/2)){
            int l = start;
            int r = l;
            while(r < s.size() && s[r] == s[r+1]){
                ++r;
            }
            start = r + 1;
            while(l > 0 && r < s.size()-1 && s[l-1] == s[r+1]){
                ++r;
                --l;
            }
            int newLen = r - l + 1;
            if(maxLen < newLen){
                maxLen = newLen;
                ml = l;
            }
        }
        return s.substr(ml, maxLen);
    }
};
