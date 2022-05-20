#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    int t;cin>>t;
    while(t--){
         int n;cin>>n;
         string bin; 
         cin>>bin;

         int start = 0;
         int end = n-1;
         int count = 0;

         while(start<end){
             if(bin[start]!=bin[end]){
                 count++;
             }
             start++;
             end--;
         }

         cout<<count<<endl;
    }
    return 0;
}