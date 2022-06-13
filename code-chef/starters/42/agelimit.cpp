#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int x,y,a;
        cin>>x>>y>>a;

        if(a>=x && a<y){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}