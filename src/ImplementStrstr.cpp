class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        if (nlen == 0)
            return 0;
        for(int i = 0;i < hlen - nlen + 1;++i){
            int j = 0;
            for(;j < nlen;++j){
                if(needle[j] != haystack[i + j])
                    break;
            }
            if(j == nlen)
                return i;
        }
        return -1;
    }
};
