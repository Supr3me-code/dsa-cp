#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        int result = n/(3*x);
        cout<<result<<endl;
    }
    return 0;
}