#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    // ll t;cin>>t;
    // while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int c = n - (a+b);
        int total = c + b;
        cout<<total<<" "<<c<<endl;
    // }
    return 0;
}