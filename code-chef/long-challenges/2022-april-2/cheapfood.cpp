// #include<bits/stdc++.h>
#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        cout<<max(x/10,100)<<endl;
    }
    return 0;
}