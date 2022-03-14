#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int score = 0;
        for(int i=0;i<3;i++){
            int a;
            cin>>a;
            if(a>score){
                score = a;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}