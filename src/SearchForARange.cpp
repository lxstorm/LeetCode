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
//it's a divide and conquer solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        return helper(nums, left, right, target);
    }
private:
    vector<int> helper(vector<int>& nums, int left, int right, int target){
        // it's the final condition
        if(nums[left] == target && nums[right] == target)
            return {left, right};
        if(nums[left] <= target && target <= nums[right]){
            int mid = (left + right) / 2;
            // get two part range, l is the left range, l[0] is the target start
            // point, r[1] is the target end point.
            vector<int> l = helper(nums, left, mid, target);
            vector<int> r = helper(nums, mid + 1, right, target);
            if(l[0] == -1)
                return r;
            if(r[1] == -1)
                return l;
            return {l[0], r[1]};
        }
        return {-1, -1};
    }
};
/******************************************************************************/
/*    two binary search methond
 *    two mid and its explanation
 *    1.it is left biased, the mid is always divided into left section;
 *    2.the second mid = (i + j) / 2 + 1，the mid is always divided into the right section;
 *    we do this because if the sequence is 0 0 0 0 1 1 1 1 1 1 2 2 2
 *    there is no difference in both case if the mid is in the 0's sequence
 *    or in the 2's sequence,
 *    when we are in the 1's sequence, in the first case, we divide know we
 *    should search the left part, when come to 0 0 0 0 1 1 ... we need to let
                                                        ^
 *    the first 1 include in the left part, so we should have (i, mid) (mid + 1, j)
 *    in the second case we should have (i, mid - 1) (mid, j)
 *    in order to have mid - 1 not less than i, we let mid = (i + j) / 2 + 1;
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size() - 1;
        vector<int> res(2, -1);

        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] < target)
                i = mid + 1;
            else
                j = mid;
        }
        if(nums[i] != target)
            return res;
        else
            res[0] = i;
        j = nums.size() - 1;
        while(i < j){
            int mid = (i + j) / 2 + 1;
            if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid;
        }
        res[1] = j;
        return res;
    }
};
*/
