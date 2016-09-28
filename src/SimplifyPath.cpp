/* my AC version use two pointer to split
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 1)
            return path;
        int slow = 0;
        int fast = 1;
        string s;
        string result;
        stack<string> pStack;

        while(fast <= path.size()){
            if(path[fast] == '/' || fast == path.size()){
                s = path.substr(slow, fast - slow);
                if(s == "/.."){
                    if(!pStack.empty())
                        pStack.pop();
                }
                else if(s == "/" || s == "/.")
                    ;
                else
                    pStack.push(s);

                slow = fast;
            }
            ++fast;
        }
        if(pStack.empty())
            pStack.push("/");
        while(!pStack.empty()){
            s = pStack.top();
            result = s + result;
            pStack.pop();
        }
        return result;
    }
};
*/
// use stringstream to split
class Solution{
public:
    string simplifyPath(string path){
        string tmp, result;
        stringstream ss(path);
        vector<string> vstk;
        while(getline(ss,tmp,'/')){
            if(tmp == "." || tmp == "") continue;
            if(tmp == ".."){
                if(!vstk.empty())
                    vstk.pop_back();
            }
            else
                vstk.push_back(tmp);
        }
        result = "";
        for(int i = 0;i < vstk.size();++i)
            result = result + "/" + vstk[i];
        return result.empty() ? "/" : result;
    }
};
