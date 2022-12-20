#include <bits/stdc++.h>
using namespace std;

bool help(int n, int k, int l, int arr[]) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    // cout<<"my friend's speed: "<<arr[n-1]<<endl;
    // cout<<"fastest speed: "<<maxi<<endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxi) count++;
    }
    if (count == 1 && arr[n - 1] == maxi) return true;
    if (k <= 0) return false;
    int myFriend = arr[n - 1];
    int drug = 0;
    // cout<<"detectable dose: "<<l<<endl;
    while (myFriend <= maxi) {
        myFriend += k;
        drug++;
        // cout<<"updated speed: "<<myFriend<<endl;
        // cout<<"updated drug dose: "<<drug<<endl;
        if (drug >= l) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (help(n, k, l, arr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}
