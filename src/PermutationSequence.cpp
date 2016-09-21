/* swap kth , time exceed
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        string res;

        for(int i = 0;i < n;++i){
            s[i] = i + 1 + '0';
        }
        helper(s, res, n, k, 0);
        return res;
    }
private:
    int cnt = 0;
    void helper(string s, string &res, int n, int k, int step){
        if(step == n){
            cnt++;
            if(cnt == k)
                res = s;
            return;
        }

        for(int i = step;i < n && cnt < k;++i){
            swap(s[i],s[step]);
            helper(s, res, n, k, step + 1);
        }
    }
};
*/
class Solution{
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        vector<int> pTable;
        string res;

        pTable.push_back(1);
        for(int i = 1;i < n;++i){
            pTable.push_back(i * pTable[i - 1]);
        }
        for(int i = 0;i < n;++i){
            num.push_back(i + 1);
        }
        // we can also first k-- before while, than use k in the while loop.
        // do not need to k - 1 while loop
        // explanation: see k is 72 and we want to try 24 6 2 1 sequencely
        // we want to have 72 = 2 * 24 + 24
        // we have k - 1, so the remainder is one less than the original(original 0
        // is 24), so when we use the remainder to be divided by 6, it's actually the k - 1
        // number.
        while(n > 0){
            int index = (k - 1) / pTable[n - 1];
            k -= index * pTable[n - 1];
            res += num[index] + '0';
            num.erase(num.begin() + index);
            --n;
        }
        return res;
    }
};
