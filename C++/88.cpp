class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n -1, i = m - 1, j = n - 1;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){ // i>= 0 to make mums1[i] valid
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};