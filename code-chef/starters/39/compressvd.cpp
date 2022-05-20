// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;

int minLength(int arr[], int n){
    if(n==1){
        return 1;
    }

    int count = 1;
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            count++;
        }
    }
    
    return count;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<minLength(arr, n)<<endl;
    }
    return 0;
}