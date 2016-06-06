// my AC version
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        if(nums[0] > target)
            return 0;
        if(nums[j] < target)
            return nums.size();
        while(i < j){
            // can improve by use mid = i + (j - i) / 2 to prevent overflow
            int mid = (i + j) / 2;
            if(nums[mid] > target)
                j = mid;
            else if(nums[mid] == target)
                return mid;
            else
                i = mid + 1;
        }
        return i;
    }
};

/* some improvement
class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (nums[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
};
*/
