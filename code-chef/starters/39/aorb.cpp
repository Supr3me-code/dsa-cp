#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;

        int Afirst,Bfirst;

        Afirst = (500 - (x*2)) + (1000 - ((x+y)*4));
        Bfirst = (1000 - (y*4)) + (500 - ((x+y)*2));

        cout<<max(Afirst,Bfirst)<<endl;
    }
    return 0;
}