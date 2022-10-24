#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,x,b,y;
	    double sA=0.0,sB=0.0;
	    cin>>a>>x>>b>>y;
	    sA = (double)a/x;
	    sB = (double)b/y;
	    if(sA > sB){
	        cout<<"Alice"<<endl;
	    }else if(sB > sA){
	        cout<<"Bob"<<endl;
	    }else{
	        cout<<"Equal"<<endl;
	    }
	}
	return 0;
}
