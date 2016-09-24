class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;
        int s;

        while(i >=0 || j >= 0 || carry){
            carry += (i >= 0 ? a[i] - '0' : 0);
            carry += (j >= 0 ? b[j] - '0' : 0);
            i--;
            j--;
            result = char(carry % 2 + '0') + result;
            carry /= 2;
        }
        return result;
    }
};
