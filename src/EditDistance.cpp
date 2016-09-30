class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int result = 0;

        vector<vector<int>> mem(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0;i <= len1;++i){
            mem[i][0] = i;
        }
        for(int i = 0;i <= len2;++i){
            mem[0][i] = i;
        }
        for(int i = 1;i <= len1;++i)
            for(int j = 1;j <= len2;++j){
                if(word1[i - 1] == word2[j - 1])
                    mem[i][j] = mem[i - 1][j - 1];
                else
                    mem[i][j] = min(mem[i - 1][j - 1] + 1, min(mem[i - 1][j] + 1, mem[i][j - 1] + 1));
            }
        return mem[len1][len2];
    }
};
