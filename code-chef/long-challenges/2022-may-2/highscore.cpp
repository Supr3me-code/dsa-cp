#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;cin>>t;
    while(t--){
        int res = INT_MIN;
        int n;
        cin>>n;
        int arr[4];
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
        for(int i=0;i<4;i++){
            res = max(res, arr[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}