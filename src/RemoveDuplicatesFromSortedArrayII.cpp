class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 0;j < nums.size();++j){
            // it's i - 2 because i is point to the index to be inserted.
            // we only need the new insert number not equal to the i - 2
            if(j < 2 || nums[j] != nums[i - 2])
                nums[i++] = nums[j];
        }
        return i;
    }
};
/*
    we can also use i that indict the last pos of the modified sub vector
*/
