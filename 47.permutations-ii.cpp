// 47. Permutations II
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans){
    
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    else {
        for(int j=index; j<nums.size(); j++){
            if(j == index || nums[j] != nums[index]) {
                swap(nums[index], nums[j]);
                solve(nums, index+1, ans);
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main() {

    vector<int> nums = {1,1,2};

    vector<vector<int>> ans = permuteUnique(nums);

    for(auto i: ans) {
        for(auto j: ans[i]) {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}