#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];

        ll ones = 0;
        ll zeros = 0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                ones++;
            }else{
                zeros++;
            }
        }
        if(n%2!=0){
            cout<<"NO"<<endl;
        }else if(ones==zeros){
            cout<<"YES"<<endl;
            cout<<1<<" "<<n<<endl;
        }else{
            
        }
    }
    return 0;
}