// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long int ll;

void recur(int a, int b, vector<int> counts, int count, bool found){
    if(a%3==0 || b%3==0){
        counts.push_back(count);
        found = true;
        return;
    }

    if(found == false){
        recur(abs(a-b), b, counts, count+1, false);
        recur(a, abs(a-b), counts, count+1, false);
    }else{
        return;
    }
    
}

int main(){
    ll t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int> counts;
        recur(a, b, counts, 0, false);
        int mini = INT_MAX;
        cout<<counts.size()<< " this is size"<<endl;
        for(int i=0;i<counts.size();i++){
            mini = min(counts[i], mini);
        }
        cout<<mini<<endl;

    }
    return 0;
}