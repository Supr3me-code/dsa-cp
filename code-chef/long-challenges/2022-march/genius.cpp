#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        ll correct, incorrect, unattempted;
        if(x>3*n){
            cout<<"NO"<<endl;
            break;
        }else{
            if(x%3==0){
                correct = x/3;
                incorrect = 0;
                unattempted = 0;
            }else{
                ll diff = ((x/3)*3) - x;
                if(diff>)
            }
        }

    }
}