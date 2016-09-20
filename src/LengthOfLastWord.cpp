class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int i = n - 1;
        int cnt = 0;
        while(s[i] == ' ' && i >= 0)
            --i;
        // we can also use s[i] != ' ' instead of isalpha()
        while(isalpha(s[i]) && i >= 0){
            --i;
            cnt++;
        }
        return cnt;

    }
};
