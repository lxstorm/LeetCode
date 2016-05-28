/* left indicates the number of left parentheses to be added into the string,
 * right is used to indicate the number of right parentheses can be added
 * into the string right now.
 *
 * the second helper var right is used to indicate how many right parentheses
 * we need to add to the string;
 *
 * each time we have two choice add a '(' or a ')';
 * we just need to make the add correct by using the left and right var;
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    void helper(vector<string> &res, string s, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }
        if(left > 0)
            helper(res, s + '(', left - 1, right + 1);
        if(right > 0)
            helper(res, s + ')', left, right - 1);
    }
};

/* another form helper
 * void helper(vector<string> &res, string s,int left, int right){
 *      if(left)            helper(res, s + '(', left-1, right);
 *      if(right > left)    helper(res, s + ')', left, right - 1);
 *      if(!right)          res.push_back(s);
 * }
 *
 *
 */
