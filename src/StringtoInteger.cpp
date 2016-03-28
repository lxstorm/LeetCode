class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int sgn = 1;
        int len = str.size();
        int i = 0;
        int start = 0;

        while(str[i] == ' ')
            ++i;
        start = i;
        if(str[i] == '-'){
            sgn = -1;
            ++i;
        }
        else if(str[i] == '+'){
            ++i;
        }
        while(i != len){
            if('0' <= str[i] && str[i] <= '9')
                res = res * 10 + (str[i] - '0');
            else {
                if(i - start == 1)
                    if(str[start] == '+' || str[start] == '-')
                        return 0;
                break;
                }
            ++i;
            if (res > INT_MAX)
                break;
        }

        res = res * sgn;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return (int)res;
    }
};
