/* use -1 to denote not appear yet
 * flag to denote the first appearance in the string
 * when compare l and flag[s[r]] + 1 we are actually to compare whether the
 * s[r] character have appeared >= l, if so we move the l to the next element
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag(256, -1);
        int l = 0;
        int r = 0;
        int maxLength = 0;
        while(r < s.size()){
            l = max(l,flag[s[r]] + 1);
            flag[s[r]] = r;
            maxLength = max(maxLength, r - l +1);
            r++;
        }
        return maxLength;
    }
};
