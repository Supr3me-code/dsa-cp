#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;

        int counter = 0;
        int gap = abs(a-b);
        
        for (int i=1; i<=sqrt(gap); i++){
            if (gap%i == 0){
                if (gap/i == i) counter += 1;
                else counter += 2;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}