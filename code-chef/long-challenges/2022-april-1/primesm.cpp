#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;

        if(a==1 || b==1){
            cout<<-1<<endl;
        }else if(
            (a==2 && b==3) ||
            (a==3 && b==2) ||
            (a==3 && b==4) ||
            (a==4 && b==3)
            ){
                cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}