class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> combination;

        elementSum(candidates,combination,result,0,target);
        return result;
    }
private:
    void elementSum(vector<int>& candidates, vector<int>& combination,
            vector<vector<int>>& result,int begin, int target){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        else{
            for(int i = begin;i < candidates.size() && target >= candidates[i];++i){
                combination.push_back(candidates[i]);
                // iterative 迭代
                elementSum(candidates, combination, result, i, target - candidates[i]);
                combination.pop_back();
            }
        }
    }
};
