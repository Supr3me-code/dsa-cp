#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;

        int sum = 0;
        int bulb;
        for(int i=0;i<n-1;i++){
            cin>>bulb;
            sum += bulb;
        }

        int z = x * n;
        int result = z - sum;

        result = max(0, result);
        cout<<result<<endl;


    }
    return 0;
}