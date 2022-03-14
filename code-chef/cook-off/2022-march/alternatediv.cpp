#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        
        int number = 1;
        cout<<number<<" ";
        for(int i=1;i<n;i++){
            if(i%2==0){
                number++;
                cout<<number<<" ";
            }else{
                number *= 2;
                cout<<number<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}