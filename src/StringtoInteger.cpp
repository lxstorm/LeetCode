class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int sgn = 1;
        int len = str.size();
        for(int i = 0;i != len;++i){
            if(i == 0){
                if(str[0] == '-')
                    sgn = -1;
                if(str[0] ==  '+')
                ;
            }
            else{
                res = res * 10 + (str[i] - '0');
                cout<<res<<endl;
            }
        }
        res = res * sgn;
        if (res > INT_MAX || res <INT_MIN)
            return 0;
        return (int)res;
    }
};
