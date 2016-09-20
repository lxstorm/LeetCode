class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int i = n - 1;
        int cnt = 0;
        while(s[i] == ' ' && i >= 0)
            --i;
        while(isalpha(s[i]) && i >= 0){
            --i;
            cnt++;
        }
        return cnt;

    }
};
