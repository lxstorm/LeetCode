/* we could not use a swap and swap back strategy, because of the duplicate.
 *    1 2' 2"    if we use swap and swap back we can not prevent 1 <--> 2' and
 *    1 <--> 2" duplicate
 * common example: 1 2 3
 * we use the value type nums vector, so after the first position's permutations
 * the sequence is
        1 2 3
          1 3 2
        2 1 3    change base on 1 2 3
          2 3 1
        3 1 2    change base on 2 1 3
          3 2 1
   for duplicate example: 1 1 2 2
   1 1 2' 2"
    1 2' 1 2"
     1 2' 2" 1
    1 2" 1 2'    XXXX this can not be swaped because our duplicate examination

  **************************
  whenever we do swap i, j(i < j),the sequence after j is in a next-permutation
  order, duplicates are one by one, so if j and j + 1 are duplicate, then we will
  not swap them after all swaped i, j permutations are counted.
  **************************
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permuteRecursive(nums, res, 0);

        return res;
    }
private:
void permuteRecursive(vector<int> nums, vector<vector<int>> &result, int begin)
    {
        if(begin >= nums.size()){
            result.push_back(nums);
            return;
        }
        else{

            for(int i = begin;i < nums.size();++i){
                if(nums[begin] != nums[i] || begin == i){
                    swap(nums[i], nums[begin]);
                    permuteRecursive(nums, result, begin + 1);
                }
            }
        }
    }
};

/* method using dfs
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        vector<vector<int>> result;
        vector<int> combination;

        for(int i = 0;i < nums.size();++i){
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 0;
            m[nums[i]]++;
        }

        dfs(nums, combination, result, m, 0);

        return result;
    }
private:
    void dfs(vector<int>& nums, vector<int>& combination, vector<vector<int>>& result,
            map<int, int> &m, int step)
    {
        if(step == nums.size()){
            result.push_back(combination);
            return;
        }
        else{
            for(map<int, int>::iterator iter = m.begin();iter != m.end();++iter){
                if(iter->second > 0){
                    (iter->second)--;
                    combination.push_back(iter->first);
                    dfs(nums, combination, result, m, step + 1);
                    combination.pop_back();
                    (iter->second)++;
                }
            }
        }
    }
};
*/
