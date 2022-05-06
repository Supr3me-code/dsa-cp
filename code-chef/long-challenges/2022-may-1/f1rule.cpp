#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;
        double limit = (107*x)/100;
        if(y<=limit){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}