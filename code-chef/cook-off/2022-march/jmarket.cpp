#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,arr[3];
        cin>>x;
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        int money = 0;
        money += arr[1];
        x--;
        for(int i=0;i<x;i++){
            money += arr[0];
        }
        cout<<money<<endl;
    }
    return 0;
}