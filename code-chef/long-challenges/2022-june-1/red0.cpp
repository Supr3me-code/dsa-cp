#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long int ll;

bool isPowerOf2(ll x){
    return x && (!(x & (x - 1)));
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        ll maxi = max(a,b);
        ll mini = min(a,b);

        if(mini==0){
            if(maxi==0) cout<<0<<endl;
            else cout<<-1<<endl;
        }
        else if(maxi%mini!=0) cout<<-1<<endl;
        else if(!isPowerOf2(maxi/mini)) cout<<-1<<endl;
        else{
            ll z = maxi/mini;
            ll counter = 0;
            while(z!=1){
                z /= 2;
                counter++;
            }
            cout<<counter+maxi<<endl;
        }
    }
    return 0;
}