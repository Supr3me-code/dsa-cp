// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;
int main(){
	ll t;
	cin>>t;
	while(t--){
		int x,y;
        cin>>x>>y;

        int length = x + y;

        char s1[length], s2[length];

        if(x%2!=0 && y%2!=0){
            cout<<-1<<endl;
        }else if(x%2==0 && y%2==0){
            for(int i=0;i<x/2;i++){
                s1[i] = 'a';
                s1[length-i-1] = 'a';
            }
            for(int i=x/2;i<x/2+y;i++){
                s1[i] = 'b';
            }
            for(int i=0;i<length;i++){
                if(s1[i] == 'a'){
                    s2[i] = 'b';
                }else{
                    s2[i] = 'a';
                }
            }
            cout<<s1<<endl<<s2<<endl;
        }else{
            if(x%2!=0){
                s1[length/2] = s2[length/2] = 'a';
                x--;
            }else{
                s1[length/2] = s2[length/2] = 'b';
                y--;
            }

            for(int i=0;i<x/2;i++){
                s1[i] = 'a';
                s1[length-i-1] = 'a';
            }

            for(int i=x/2;i<x/2+y;i++){
                if(i==length/2){
                    continue;
                }else
                    s1[i] = 'b';
            }

            for(int i=0;i<length;i++){
                if(i==length/2){
                    continue;
                }
                else if(s1[i] == 'a'){
                    s2[i] = 'b';
                }else{
                    s2[i] = 'a';
                }
            }

            cout<<s1<<endl<<s2<<endl;
        }
	}
    return 0;
}