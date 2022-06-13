#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        if((a+b)%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}