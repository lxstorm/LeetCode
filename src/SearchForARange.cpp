/* my first AC solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;

        return find(front, back, nums, target);
    }
    vector<int> find(int front, int back, vector<int>& nums, int target){
        int mid = (front + back) / 2;
        vector<int> res(2, -1);
        if(front == back && nums[front] != target)
            return {-1,-1};
        if(nums[mid] < target)
            res = find(mid + 1, back, nums, target);
        if(nums[mid] > target)
            res = find(front, mid, nums, target);
        if(nums[mid] == target){
            res[0] = findFirst(front, mid, nums, target);
            res[1] = findLast(mid, back, nums, target);
        }
        //cout<<front<<"---"<<back<<endl;
        return res;
    }
    int findFirst(int front, int back, vector<int>& nums, int target){
        int mid = (front + back) / 2;
        if(nums[front] == target)
            return front;
        if(front == back)
            return front;
        if(nums[mid] < target)
            return findFirst(mid + 1, back, nums, target);
        //if(nums[mid] == target)
        else
            return findFirst(front, mid, nums, target);
    }

    int findLast(int front, int back, vector<int>& nums, int target){
        cout<<front<<"---"<<back<<endl;
        if(nums[back] == target)
            return back;
        if(front == back)
            return front;
        int mid = (front + back) / 2;
        if(nums[mid] == target)
            return findLast(mid , back - 1, nums, target);
        //if(nums[mid] > target)
        else
            return findLast(front, mid, nums, target);
    }
};
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        return helper(nums, left, right, target);
    }
    vector<int> helper(vector<int>& nums, int left, int right, int target){
        if(nums[left] == target && nums[right] == target)
            return {left, right};
        if(nums[left] <= target && target <= nums[right]){
            int mid = (left + right) / 2;
            vector<int> l = helper(nums, l, mid, target);
            vector<int> r = helper(nums, mid + 1, right, target);
            if(l[0] == -1)
                return right;
            if(right[1] == -1)
                return left;
            return {left[0], right[1]};
        }
        return {-1, -1};
    }
};
