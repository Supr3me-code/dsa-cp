#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        ll i = 1;
        ll j = 0;
        if(n%2==1){
            arr[0] = x;
            j++;
        }
        while(j<n){
            arr[j++] = x+i;
            arr[j++] = x-i;
            i++;
        }
        for(int k;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}