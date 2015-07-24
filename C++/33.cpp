class Solution {
public:
    /*Version1 offset 4ms 
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        //int offset = 0; 
        //if(nums.size()>1)
        //    while(offset<1||nums[offset-1]<nums[offset]&&offset<length)offset++;
        int offset = min_element(nums.begin(),nums.end()) - nums.begin(); // a easy way~
        int left = 0;
        int right = length-1;
        while(left<=right){
            int mid = (left+right)/2;
            int mid_offset = mid + offset; // map method
            if(mid_offset>=length) mid_offset -= length;
            if(nums[mid_offset]==target) return mid_offset;
            if(nums[mid_offset]>target) right = mid-1; 
            else left = mid + 1;
        }
        return -1;
    }
    */
    
    //Version2 4ms
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid])
                if(nums[left]<=target&&target<nums[mid]) right = mid-1;
                else left = mid + 1;
            else 
                if(nums[mid]<target&&target<=nums[right]) left = mid+1;
                else right = mid-1;
        }
        return -1;
    }
};