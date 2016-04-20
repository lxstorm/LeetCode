class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int id = 0;
        for(int i = 0;i < len;++i){
            if(nums[i] != val){
                nums[id] = nums[i];
                ++id;
            }
        }
        return id;
    }
};
