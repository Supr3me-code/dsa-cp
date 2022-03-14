#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    if(n<6){
	        cout<<0<<endl;
	    }else{
	        cout<<(n+1)/7<<endl;
	    }
	}
	return 0;
}