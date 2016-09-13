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
        // see how combination change
        // for(int i = 0;i<combination.size();++i){
        //     cout<<combination[i]<<" ";
        // }
        cout<<endl;
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
/* if candidates is [10,11,12] target is 33
 * combination:
    10
    10 10
    10 10 10
    10 10 11
    10 10 12
    10 11
    10 11 11
    10 11 12
    10 12
    11
    11 11
    11 11 11
    11 12
    12
    12 12
 */
