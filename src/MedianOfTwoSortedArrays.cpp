class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if((m + n) & 1){
            return findkth(nums1, 0, m, nums2, 0, n, (m + n ) / 2 + 1);
        }
        else
            return (findkth(nums1, 0, m, nums2, 0, n, (m + n) / 2)
                + findkth(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1)) / 2.0;

    }
private:
    double findkth(vector<int>& nums1, int l1, int m, vector<int> &nums2,
                    int l2, int n, int k)
    {
        if(m > n)
            return findkth(nums2, l2, n, nums1, l1, m, k);
        if(m == 0)
            return nums2[l2 + k - 1];
        if(k == 1)
            return min(nums1[l1], nums2[l2]);
        int i = min(m, k / 2);
        int j = k - i;
        if(nums1[l1 + i - 1] > nums2[l2 + j - 1])
            return findkth(nums1, l1, i, nums2, l2 + j, n - j, k - j);
        else
            return findkth(nums1, l1 + i, m - i, nums2, l2, j, k - i);
    }
};
