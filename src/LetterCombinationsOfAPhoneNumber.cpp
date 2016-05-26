class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> phone = {
            {""},
            {""},{"abc"},{"def"},
            {"ghi"},{"jkl"},{"mno"},
            {"pqrs"},{"tuv"},{"wxyz"}
        }
        vector<string> res;

        for(int i = 0;i < digits.size();++i){
            if(digits[i] > '9' && digits[i] < '2')
                return
        }

    }
};
