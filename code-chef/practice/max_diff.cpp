#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int maxDiff = INT_MIN;
        for(int i=0;i<=n;i++){
            int first = i;
            int second = s-i;
            if(second>0 and second<=n)
                maxDiff = max(maxDiff, abs(first-second));
        }
        cout<<maxDiff<<endl;
    }
}