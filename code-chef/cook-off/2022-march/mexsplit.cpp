#include<iostream>
#include<vector>
using namespace std;

int mex(){
    int n;cin>>n;
    int result = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        result += (arr[i]==0);
    }
    return max(result, n-result);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<mex()<<endl;
    }
}