class Solution {
public:
    string convert(string s, int numRows) {
        string resString;
        int numCols = (s.size() / (numRows + 1) + 1) * 2;
        char a[numRows][numCols];
        for(int i = 0;i < numRows;++i)
            for(int j = 0;j < numCols;++j)
                a[i][j] = NULL;
        for(int i = 0;i < s.size();++i){
            int newRow;
            int newCol;
            int tmpR;
            int tmpC;
            //see two cols as a whole part
            tmpR = i % (numRows + 1);
            tmpC = i / (numRows + 1);
            if(tmpR == numRows){
                newRow = (numRows + 1) / 2 - 1;
                newCol = tmpC * 2 + 1;
            }
            else{
                newRow = tmpR;
                newCol = tmpC * 2;
            }
            a[newRow][newCol] = s[i];
        }
        for(int i = 0;i < numRows;++i)
            for(int j = 0;j < numCols;++j){
                if(a[i][j] != NULL)
                    resString += a[i][j];
                    cout<<a[i][j]<<endl;
            }
        return resString;
    }
};
