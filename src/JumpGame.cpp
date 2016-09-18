/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool result;

        result = dfs(nums, 0);

        return result;

    }
private:
    bool dfs(vector<int>& nums, int index){
        if(index >= nums.size() - 1){
            return true;
        }
        bool flag = false;
        // or we can use i from i + 1 to i + nums[index], this can avoid infinite
        // loop when nums[index] == 0
        if(nums[index] == 0)
            return false;
        for(int i = nums[index];i > 0 && flag == false;--i){
            flag = dfs(nums, index + i);
        }

        return flag;
    }
};
*/
class Solution{
public:
    bool canJump(vector<int>& nums){
        int len = nums.size();
        int maxReach = 0;
        for(int i = 0;i < nums.size() && i <= maxReach;++i){
            maxReach = max(maxReach, i + nums[i]);
        }
        if(maxReach >= len - 1)
            return true;
        else
            return false;
    }
};
