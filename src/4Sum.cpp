/* my AC version
    we can make it faster by add
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
    in the loop 1;
    and add
        if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
        if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
    int the loop 2;
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> quadruplet(4, 0);
        std::sort(nums.begin(), nums.end());
        if(nums.size() < 4)
            return res;

        for(int i = 0;i < nums.size();++i){
            for(int j = i + 1;j < nums.size();++j){
                int front = j + 1;
                int back = nums.size() - 1;
                //cout<<nums[j]<<endl;
                while(front < back){
                    int sum = nums[i] + nums[j] + nums[front] + nums[back];
                    if(sum < target)
                        front++;
                    else if(sum > target)
                        back--;
                    else{
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);

                        while(front < back && nums[front] == quadruplet[2])
                            ++front;
                        while(front < back && nums[back] == quadruplet[3])
                            --back;
                    }
                }
                while(j + 1 < nums.size() && nums[j + 1] == nums[j])
                    ++j;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
