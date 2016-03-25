/*

    P.......A........H.......N
    ..A..P....L..S....I...I....G
    ....Y.......I........R

*/
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <= 1)
            return s;
        if (numRows == 1)
            return s;
        string *str = new string[numRows];
        string res = "";
        int row = 0;
        int step = 1;
        for (int i = 0;i < len;++i){
            if(row == 0)
                step = 1;
            if(row == numRows - 1)
                step = -1;
            str[row] += s[i];
            row += step;
        }
        cout<<1<<endl;
        for(int i = 0;i < numRows;++i){
            res += str[i];
        }
        return res;
    }
};
