class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    bool check = binary_search(nums.begin(), nums.end(), target);

      if (check == false)
        return {-1, -1};
        
      int first_pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      int last_pos  = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

      return {first_pos, last_pos};    
    }
};
