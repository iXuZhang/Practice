class Solution {
public:
    /* Version1 bad one
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        double res = (nums1[nums1.size()/2] + nums1[(nums1.size()-1)/2])/2.0; // Median
        return res;
    }
    */
    //Version2 O(log (m+n)) Binary search. Awesome!
    //Call 2 times getkth and k is about half of (m + n). Every time call getkth can reduce the scale k to its half. So the time complexity is log(m + n).
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) >> 1;
        int right = (m + n + 2) >> 1;
        return (getKth(nums1, 0, nums2, 0, left, m , n) + getKth(nums1, 0, nums2, 0, right, m, n))/2.0;
    }

private:
    //Return kth value
    int getKth(const vector<int>& nums1, int begin1, const vector<int>& nums2, int begin2, int k, int m, int n){
        if (begin2 == n ) 
            return nums1[begin1 + k - 1];
        if (begin1 == m )
            return nums2[begin2 + k - 1];
        if (k == 1)
            return min(nums1[begin1], nums2[begin2]);
        int i = min(m, begin1 + k / 2); 
        int j = min(n, begin2 + k / 2);
        if (nums1[i - 1 ] > nums2[j - 1])
            return getKth(nums1, begin1, nums2, j, k-j+begin2, m, n);
        else
            return getKth(nums1, i, nums2, begin2, k-i+begin1, m, n);
        return 0;
    }
};