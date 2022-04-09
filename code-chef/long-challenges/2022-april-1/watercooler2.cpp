#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        
        int m = y/x;

        if(y%x==0){
            cout<<m-1<<endl;
        }else{
            cout<<m<<endl;
        }
    }
    return 0;
}