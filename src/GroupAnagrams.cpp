class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> m;

        for(int i = 0;i < strs.size();++i){
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(tmp);
        }
        for(map<string, vector<string>>::iterator iter = m.begin();iter != m.end();++iter){
            sort(iter->second.begin(), iter->second.end());
            result.push_back(iter->second);
        }
        return result;
    }
};
