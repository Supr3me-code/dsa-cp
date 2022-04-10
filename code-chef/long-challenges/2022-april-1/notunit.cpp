#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int range = b-a+1;

        if(a%2==0){
            if(range>2){
                cout<<a<<" "<<a+2<<endl;
            }else{
                cout<<-1<<endl;
            }
        }else if(range>3){
            if(a%3==0){
                cout<<a<<" "<<a+3<<endl;
            }else{
                cout<<a+1<<" "<<a+3<<endl;
            }
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}