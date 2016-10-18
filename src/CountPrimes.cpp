class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)  return 0;
        vector<bool> primeList(n, true);
        primeList[0] = false;
        primeList[1] = false;
        int sum = n - 2, rt = sqrt(n);
        for(int i = 2;i <= rt;++i)
            if(primeList[i]){
                for(int j = i * i;j < n;j += i){
                    if(primeList[j]){
                        --sum;
                        primeList[j] = false;
                    }
                }
            }
        return sum;
    }
};
