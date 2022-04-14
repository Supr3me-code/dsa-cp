#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll arr[n];
        ll positive = 0;
        ll negative = 0;

        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0){
                positive++;
            }else if(arr[i]<0){
                negative++;
            }
        }

        
        ll result = 0;
        for(ll i=0;i<n;i++){
            if(arr[i]>0){
                result += --positive;
            }else if(arr[i]<0){
                result += --negative;
            }
        }
        cout<<result<<endl;

    
    }
    return 0;
}