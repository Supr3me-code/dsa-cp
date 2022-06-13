#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int mo = 0, po = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==-1) mo++;
            else po++;
        }

        int diff = abs(po - mo);
        if(diff%2==0) cout<<diff/2<<endl;
        else cout<<-1<<endl;


    }
    return 0;
}