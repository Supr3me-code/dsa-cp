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
         int res = count/2 + count%2; //if there are 2 pairs that mismatch, they can be corrected in 1 step
         //ex. 1111000 -> 1 step: xor bin[0] and bin[1]; (both 1s become 0 and matches with the corresponding 0s on the right side of the string)
         //then xor bin[2] and bin[4]; 
         // so if there are n pairs that mismatch -> can be solved in n/2 steps.. if n is odd, 1 pair will be left so xor the 0 and 1 to make them 1

         cout<<res<<endl;
    }
    return 0;
}