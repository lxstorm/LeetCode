class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charmap(128);
        // postive means need nums, zero means not need now, negative means the
        // nums of char in the window is over needed
        for(int i = 0;i < t.size();++i)
            charmap[t[i]]++;
        int start = 0, minStart = 0, minLen = INT_MAX, cnt = t.size();
        for(int end = 0;end < s.size();++end){
            if(charmap[s[end]] > 0)
                cnt--;
            charmap[s[end]]--;
            while(cnt == 0){
                if(end - start + 1 < minLen){
                    minStart = start;
                    minLen = end - start + 1;
                }
                charmap[s[start]]++;
                if(charmap[s[start]] > 0)
                    cnt++;
                start++;
            }
        }
        if(minLen == INT_MAX)
            return "";
        return s.substr(minStart, minLen);
    }
};
