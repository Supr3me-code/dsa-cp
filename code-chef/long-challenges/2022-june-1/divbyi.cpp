#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;

        int numberToBeSubtractedOrAdded = n-1;
        bool subtract = true;
        int currentNumber = n;
        int result[n];
        result[n-1] = currentNumber;
        for(int i=n-2;i>=0;i--){
            if(subtract){
                currentNumber -= numberToBeSubtractedOrAdded;
                subtract = false;
                numberToBeSubtractedOrAdded--;
                result[i] = currentNumber;
            }else{
                currentNumber += numberToBeSubtractedOrAdded;
                subtract = true;
                numberToBeSubtractedOrAdded--;
                result[i] = currentNumber;
            }
        }
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
    }
    return 0;
}