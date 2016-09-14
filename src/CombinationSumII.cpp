class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;

        dfs(candidates,result, combination, 0, target);

        return result;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>  &result,
        vector<int> &combination, int begin, int target){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        else{
            for(int i = begin;i < candidates.size() && candidates[i] >= target;++i){
                combination.push_back(candidates[i]);
                dfs(candidates, result, combination, i + 1, target - candidates[i]);
                combination.pop_back();

                // skip duplicate in the end of for, don't skip in the dfs, this may
                // cause [1 1 2 5] target = 2 miss the [1 1] solution
                while(i + 1 < candidates.size() && candidates[i + 1] == candidates[i])
                    ++i;
            }
            return;
        }
    }
};
