class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> triplet(3,0);

        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();++i){
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while(front < back){
                int sum = nums[front] + nums[back];
                //use if else not 3 if statement because they are parallel;
                if(sum < target)
                    ++front;
                else if(sum > target)
                    --back;
                else{
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    //only need to note the duplicate when the sum is 0;
                    //front--> with <--back is the right motion;
                    while(front < back && nums[front] == triplet[1] )
                        ++front;
                    while(front < back && nums[back] == triplet[2])
                        --back;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])//use while not if!
                ++i;
        }
        return res;
    }
};
