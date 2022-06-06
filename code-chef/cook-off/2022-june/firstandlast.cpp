#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int maxi = arr[0] + arr[n-1];

        for(int i=1;i<n;i++){
            maxi = max(maxi, arr[i] + arr[i-1]);
        }
        cout<<maxi<<endl;

    }
    return 0;
}