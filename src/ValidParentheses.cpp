/* former solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        char tmpIn;
        char tmpOut;
        for(int i = 0;i < s.size();++i){
            tmpIn = s[i];
            if(tmpIn == '(' || tmpIn == '[' || tmpIn == '{')
                mystack.push(s[i]);
            if(tmpIn == ')' || tmpIn == ']' || tmpIn == '}'){
                if(mystack.empty())
                    return false;
                tmpOut = mystack.top();
                if((tmpIn == ')' && tmpOut != '(')
                || (tmpIn == ']' && tmpOut != '[')
                || (tmpIn == '}' && tmpOut != '{'))
                    return false;
                mystack.pop();

            }
        }
        if(mystack.empty())
            return true;
        else
            return false;
    }
};
*/

// a try to use stack and map
class Solution{
public:
    bool isValid(string s){
        stack<char> st;
        map<char,char> m={{')', '('},{']', '['},{'}', '{'}};
        for(int i = 0;i < s.size();++i){
            tmp = s[i];
            if(tmp == '(' || tmp == '[' || tmp == '{')
                st.push(tmp);
            if(tmp == ')' || tmp == ']' || tmp == '}'){
                if(st.empty() || st.top() != m[tmp])
                    return false;
                st.pop();
            }
            return st.empty();
        }
    }
}
