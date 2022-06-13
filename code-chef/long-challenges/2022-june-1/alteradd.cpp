#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        if((b-a)%3==0 || (b-a-1)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}