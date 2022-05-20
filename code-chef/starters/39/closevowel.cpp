#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

unsigned long long result(string s, int n){
    const unsigned int M = 1000000007;
    unsigned long long count = 1;
    for(ll i=0;i<n;i++){
        if(s[i]=='c' or s[i]=='g' or s[i]=='l' or s[i]=='r'){
            count = (count*2)%M;
        }
    }
    return count;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        string input;
        cin>>input;

        cout<<result(input, n)<<endl;
    }
    return 0;
}