#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll x,n;cin>>x>>n;

        cout<<(x-1)*(2*n-x)<<endl;
    }
    return 0;
}