class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');

        for(int i = num1.size() - 1;i >= 0;--i){
            int carry = 0;
            for(int j = num2.size() - 1;j >= 0;--j){
                int tmp = result[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                result[i + j + 1] = tmp % 10 + '0';
            }
            if(carry != 0)
                result[i] = carry + '0';
        }
        int i;
        for(i = 0;i < result.size() - 1 && result[i] == '0';++i){
        }
        return result.substr(i);
    }
};
