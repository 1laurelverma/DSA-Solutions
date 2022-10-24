#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll n;ll x;
	    cin>>n;
	    ll max=0;
	    ll min=0;
	    vector <ll> posi;
	    vector <ll> neg;
	    for(ll i =0;i<n;i++){
	        cin>>x;
	        if(x < 0){
	            neg.push_back(x);
	        }else{
	            posi.push_back(x);
	        }
	    }
	    sort(posi.begin(),posi.end());
	    sort(neg.begin(),neg.end());
	    if(neg.empty()){
	        max = posi.back()*posi.back();
	        min = posi.front()*posi.front();
	    }else if(posi.empty()){
	       max = neg.front()*neg.front();
	        min = neg.back()*neg.back(); 
	    }
	    else{
	        if(neg.front()*neg.front()< posi.back()*posi.back()){
	            max = posi.back()*posi.back();
	        }
	        else{
	            max = neg.front()*neg.front();
	        }
	        min = neg.front() * posi.back();
	    }
	    cout<<min<<" "<<max<<endl;
	    
	}
	return 0;
}