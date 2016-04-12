class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strCnt = strs.size();
        int end = strs[0].size();
        if(strCnt == 0 || end == 0)
            return "";

        for(int i = 1; i < strCnt; ++i){
            end = min(strs[i].size(), end);
            if(end <= 0)
                return "";
            for(int j = 0; j < end; ++j)
                if(strs[i][j] != strs[0][j]){
                    end = j - 1;
                    break;
                }
        }
        return strs.substr(0, end);
    }
};
