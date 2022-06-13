#include<iostream>
#include<set>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string a,b;
        cin>>a>>b;

         set<char> s;
         for(int i=0;i<n;i++){
             if(a[i]!=b[i]) s.insert(b[i]);
         }
         ll count = s.size();
         cout<<count<<endl;
    }
    return 0;
}