class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        int id = nums.size() - 1;


        while(id - 1 >= 0){
            if(nums[id - 1] < nums[id]){
                break;
            }
            --id;
        }
        // can also use reverse function below
        if(id == 0){
            int front = 0;
            int back = nums.size() - 1;
            while(front < back){
                swap(nums[front],nums[back]);
                ++front;
                --back;
            }
        }
        else{
            int j;
            for(int i = nums.size() - 1;i > id - 1;--i){
                if(nums[i] > nums[id - 1]){
                    j = i;
                    break;
                }
            }
            swap(nums[j], nums[id - 1]);
            reverse(nums.begin() + id, nums.end());
        }
    }
};
