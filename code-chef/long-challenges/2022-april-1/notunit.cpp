#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

bool gcdNotUnit(int x, int y){
    if(gcd(x,y)>1){
        return true;
    }else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        bool found = false;
        cin>>a>>b;

        for(int x=a;x<b;x++){
            for(int y=x+1;y<=b;y++){
                if(gcdNotUnit(x,y)){
                    cout<<x<<" "<<y<<endl;
                    found = true;
                    break;
                }
            }
        }

        if(!found)
            cout<<-1<<endl;
    }
    return 0;
}