#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n,x,y;
        cin>>n>>x>>y;
        int result = 2 * (n-1);

        int top = x - 1;
        int bottom = n - x;
        int left = y - 1;
        int right = n - y;

        result += min(right,top) + min(top, left) + min(left, bottom) + min(bottom, right);
        cout<<result<<endl;
    }
    return 0;
}