class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strCnt = strs.size();
        if(strCnt == 0)
            return "";
        int end = strs[0].size();
        if(end == 0)
            return "";

        for(int i = 1; i < strCnt; ++i){
            int slen = strs[i].size();
            end = min(slen, end);
            if(end <= 0)
                return "";
            for(int j = 0; j < end; ++j)
                if(strs[i][j] != strs[0][j]){
                    end = j;
                    break;
                }
        }
        return strs[0].substr(0, end);
    }
};
