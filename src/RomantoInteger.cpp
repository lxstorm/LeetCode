class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int res = 0;
        if(len == 0)
            return 0;
        if(len == 1)
            return getValue(s[0]);
        int i = 0, j = 1;
        int val1 = 0, val2 = 0;
        while(j < s.size()){
            val1 = getValue(s[i]);
            val2 = getValue(s[j]);
            if(val1 >= val2)
                res += val1;
            else
                res -= val1;
            ++i;
            ++j;
        }
        res += getValue(s[j - 1]);
        return res;
    }
private:
    int getValue(char c){
        switch(c){
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
        }
    }
};
