class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h=nums.size()-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]==target){
                return m;
            }
            if(nums[l] <= nums[m]){
                 if(target >= nums[l] && nums[m]>target){
                     h=m-1;
                 }         
                 else{
                     l = m+1;
                 }      
            }else{
                if(target > nums[m] && target<=nums[h]){
                     l=m+1;
                 }         
                 else{
                     h = m-1;
                 }  
            }
        }
        return -1;
    }
};
