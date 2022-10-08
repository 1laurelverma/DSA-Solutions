// Author : Chinmay Lohani
// Dated : 09.10.2022
// Timestatmp : 1665262265063

#include<bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size(),ans=1e5;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        int l=i+1, r=n-1;
        while(l<r){
            int sum=nums[i]+nums[l]+nums[r];
            if(sum==target){
                return sum;
            }
            if(abs(sum-target)<abs(ans-target)){
                ans=sum;
            }
            sum<target ? l++ : r--;
        }
    }
  return ans;
}

int main()
{
  vector<int> nums;
  int n;
  cin >> n;
  while(n--) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  int target;
  cin >> target;
  cout << threeSumClosest(nums , target);
  return 0;
}
