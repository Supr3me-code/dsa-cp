#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n], m=0;
        map<int, int> map1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            m = max(m, arr[i]);
            map1[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            m = max(m, arr[i]+map1[arr[i]]-1);
        }
        cout<<m<<endl;
    }
    return 0;
}
