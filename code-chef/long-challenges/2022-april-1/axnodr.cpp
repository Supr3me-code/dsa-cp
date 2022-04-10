// #include<bits/stdc++.h>
#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        n--;

        ll aux = n%4;

        if(aux==1 || aux==2){
            cout<<3<<endl;
        }else if(aux==3){
            cout<<n+4<<endl;
        }else{
            cout<<n+1<<endl;
        }
    }
    return 0;
}