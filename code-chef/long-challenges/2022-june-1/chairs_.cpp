#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        if(y<x){
            cout<<x-y<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}