class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for(int i = 0;i <= r;++i){
// Because the loop is from 0 to A.length-1, that is, small to large, left to right.
// In this way, if some swapping steps in (A[i]==0) break the order , it will be solved in the next i.
// But if some swapping steps in (A[i]==2) break the order, it will not be solved ,as the i has passed .
            while(nums[i] == 2 && i < r)
                swap(nums[i], nums[r--]);
            while(nums[i] == 0 && i > l)
                swap(nums[i], nums[l++]);
        }
    }
};
