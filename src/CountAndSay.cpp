class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
            return "";

        string res = "1";
        string nres;
        while(--n){
            nres = "";
            for(int i = 0; i < res.size();++i){
                int cnt = 1;
                while(i < res.size() - 1 && (res[i] == res[i + 1])){
                    ++cnt;
                    ++i;
                }
            nres += cnt + '0';
            nres += res[i];
            }
            res = nres;
        }
        return res;
    }
};
