#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;

        if(a==1 || b==1){
            cout<<-1<<endl;
        }else if(__gcd(a,b)==1){
                cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}