/* my first AC version is also fast if delete the if-statement in line 25~26
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> phone = {
            "",
            "","abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };
        int char_per_key[] = {  0,
                            0, 3, 3,
                            3, 3, 3,
                            4, 3, 4};
        vector<string> res;
        if(digits.size() == 0)
            return res;
        int num_index[digits.size()] = {0};

        int flag = 0;
        while(flag < digits.size()){
            string tmp = "";
            for(int i = 0;i < digits.size();++i){
                if(digits[i] > '9' && digits[i] < '2')
                    return res;
                tmp += phone[digits[i] - '0'][num_index[i]];
            }
            res.push_back(tmp);
            for(int i = 0;i < digits.size();++i){
                num_index[i]++;
                if(num_index[i] == char_per_key[digits[i] - '0']){
                    num_index[i] = 0;
                    flag = i + 1;
                }
                else
                    break;
            }
        }
        return res;
    }
};
*/
class Solution{
public:
    vector<string> letterCombinations(string digits){
        vector<string> res;
        string charmap[] = {"","","abc","def","ghi","jkl","mno",
                            "pqrs","tuv","wxyz"};
        if(digits.size() == 0)
            return res;
        res.push_back("");
        for(int i = 0;i < digits.size();++i){
            string tmpchar = charmap[digits[i] - '0'];
            vector<string> tmpres;
            for(int j = 0;j < res.size();++j)
                for(int k = 0;k < tmpchar.size();++k)
                    tmpres.push_back(res[j] + tmpchar[k]);
            res = tmpres;
        }
        return res;
    }
};
