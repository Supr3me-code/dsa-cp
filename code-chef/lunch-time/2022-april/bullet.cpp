#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;

        int t1 = y/x;
        if(z-t1<0){
            cout<<0<<endl;
        }else{
            cout<<z-t1<<endl;
        }
    }
    return 0;
}