#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    
    int counter = 0;
    for(int i = 0;i<4;i++){
        int p;
        cin>>p;
        if(p>9)
            counter++;
    }
    cout<<counter<<endl;
    
    return 0;
}