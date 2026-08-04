class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Hamesha binary search chhoti array par chalegi
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;

        while(l <= r) {

            // nums1 me partition
            int Px = l + (r - l) / 2;

            // nums2 me partition
            int Py = (m + n + 1) / 2 - Px;

            // Left side ke last elements
            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            // Right side ke first elements
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            // Correct partition
            if(x1 <= x4 && x2 <= x3) {

                // Total elements odd
                if((m + n) % 2 == 1)
                    return max(x1, x2);

                // Total elements even
                return (max(x1, x2) + min(x3, x4)) / 2.0;
            }

            // Left move
            else if(x1 > x4) {
                r = Px - 1;
            }

            // Right move
            else {
                l = Px + 1;
            }
        }

        return -1;
    }
};