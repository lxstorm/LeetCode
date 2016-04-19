// first AC soluition
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int>::iterator i;
        if(len < 2)
            return len;
        for(i = nums.end() - 1;i > nums.begin();--i){
            if(*i == *(i - 1)){
                --len;
                nums.erase(i);
            }
        }
        return len;
    }
};
*/
//
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int id = 0;
        for(int i = 0;i < nums.size();++i){
            if(i == 0 || nums[i] != nums[id - 1])
                nums[id++] = nums[i];
        }
        return id;
    }
};
