// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a = 0;
        int b = 0;
        for(int i=0;i<n;i++){
            string input;
            cin>>input;
            if(input == "START38")
                a++;
            else    
                b++;
        }

        cout<<a<<" "<<b<<endl;
    }
    return 0;
}