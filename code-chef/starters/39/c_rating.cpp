#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int diff = y - x;
        if(diff%8==0){
            cout<<diff/8<<endl;
        }else{
            cout<<(diff/8) + 1<<endl;
        }
    }
    return 0;
}