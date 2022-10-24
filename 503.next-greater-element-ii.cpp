// 503. Next Greater Element II
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

    int n = nums.size();
    nums.resize(2*n);

    for(int i=n; i<2*n; i++)
        nums[i] = nums[i-n];

    stack<int> s;
    vector<int> ans;

    for(int i=2*n-1; i>=0; i--) {

        if(s.empty()) {
            ans.push_back(-1);
            s.push(nums[i]);
        }
        
        else {
            while(!s.empty() && s.top() <= nums[i])
                s.pop();
            
            if(!s.empty())
                ans.push_back(s.top());
            else
                ans.push_back(-1);

            s.push(nums[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    
    ans.erase(ans.begin()+n, ans.end());
    
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);
    for(auto i: ans)
        cout << i << " ";
    return 0;
}