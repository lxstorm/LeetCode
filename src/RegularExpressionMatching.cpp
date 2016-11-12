class Solution {
public:
    bool isMatch(string s, string p) {
        // f[i][j] s[0 ... i-1] matches p[0 ... j-1]
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for(int i = 1;i < m + 1;++i)
            f[i][0] = false;

        for(int i = 1;i < n + 1;++i)
        // because of f[0][i - 2], we need to check the i is greater than 1
            f[0][i] = i > 1 && p[i - 1] == '*' && f[0][i - 2];

        for(int i = 1;i < m + 1;++i)
            for(int j = 1;j < n + 1;++j){
                if(p[j - 1] == '*')
                // valid regular expression p[0] cannot be '*'
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
                else
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
            }
        return f[m][n];

    }
};
