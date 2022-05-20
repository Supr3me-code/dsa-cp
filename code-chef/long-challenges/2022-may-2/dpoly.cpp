#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    int t;cin>>t;
    while(t--){
         int n;
         cin>>n;
         int arr[n];
         for(int i=0;i<n;i++){
             cin>>arr[i];
         }

         for(int i=n-1;i>=0;i--){
             if(arr[i]!=0){
                 cout<<i<<endl;
                 break;
             }
         }
    }
    return 0;
}