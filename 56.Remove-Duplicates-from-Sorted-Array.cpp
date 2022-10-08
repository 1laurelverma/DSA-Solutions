#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {

    if(arr.size() == 0)
        return 0;

    int i = 0;

    for(int j=1; j<n; j++) {
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i+1;
}

int main() {

    vector<int> arr = {3,3,3,4,4};

    cout << removeDuplicates(arr, arr.size());

    return 0;
}