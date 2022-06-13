#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        if(n%6==0){
            cout<<(n/6)*x<<endl;
        }else{
            cout<<((n/6) + 1) * x<<endl;
        }
    }
    return 0;
}