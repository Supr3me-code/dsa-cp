#include <bits/stdc++.h>
typedef long long int li;

using namespace std;

signed main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    li t = 1;
    cin >> t;
    while(t--){
        li n,x;
        cin >> n >> x;
        if(x == 1){
            cout << "YES" << endl;
            continue;
        }
        if(x%2 == 0){
            li op = n - x;
            if(op %2 != 0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}