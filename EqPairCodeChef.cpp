#include <iostream>
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll pairs = 0;
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i =0;i<n;i++){
	        cin>>arr[i];
	    }
	    map<ll,ll> rep;
	    for(ll i =0;i<n;i++){
	        rep[arr[i]]++;
	    }
	    for(auto x : rep){
	            pairs+=(x.second*(x.second-1))/2;
	    }
	    rep.clear();
	    cout<<pairs<<endl;
	}
	return 0;
}
