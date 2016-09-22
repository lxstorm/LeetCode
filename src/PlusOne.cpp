class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sgn = 1;
        int carry = 1;

        // we can use ++digits[i], because if carry, then digits[i] always plus 1
        for(int i = digits.size() - 1;i >= 0;--i){
            int tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if(carry != 0)
            digits.insert(digits.begin(), 1);

        return digits;


    }
};
