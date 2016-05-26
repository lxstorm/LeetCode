class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cloest = nums[0] + nums[1] + nums[nums.size() - 1];

        for(int i = 0;i < nums.size();++i){
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back){
                int sum = nums[i] + nums[front] + nums[back];
                int distance = abs(sum - target);

                if(distance < abs(cloest - target))
                    cloest = sum;
                if(sum < target)
                    ++front;
                else if(sum > target)
                    --back;
                else
                    return target;
            }
        }
        return cloest;
    }
};
