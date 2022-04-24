// #include<bits/stdc++.h>
#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;

        int first = a*10;
        int second = b*5;

        if(first>second)
            cout<<"FIRST"<<endl;
        else if(second > first)
            cout<<"SECOND"<<endl;
        else    
            cout<<"ANY"<<endl;
        
    }
    return 0;
}