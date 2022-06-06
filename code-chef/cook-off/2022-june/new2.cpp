#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,x; cin>>n>>x;

        int x2 = n - x;

        if(x%2==x2%2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}