#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isGood(string str, int size) {
    int a = 0;  // 10
    int b = 0;  // 01
    // cout<<"STRING: "<<str<<endl;
    for (int i = 0; i < size - 1; i++) {
        if (str[i] == '0') {
            if (str[i + 1] == '1') {
                b++;
            }
        } else {
            if (str[i + 1] == '0') {
                a++;
            }
        }
    }
    if (a == b)
        return true;
    else
        return false;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        string bin;
        cin >> bin;
        int counter = 0;
        int size = bin.size();

        int a = 0;  // 10
        int b = 0;  // 01
        // cout<<"STRING: "<<str<<endl;
        for (int i = 0; i < size - 1; i++) {
            if (bin[i] == '0') {
                if (bin[i + 1] == '1') {
                    b++;
                }
            } else {
                if (bin[i + 1] == '0') {
                    a++;
                }
            }
        }

        // for(int i=1;i<size-1;i++){
        //     if(bin[i-1]!=bin[i+1]){
        //         if(a==b) counter++;
        //     }
        // }
        if (a == b) {
            counter = size - 2;
        }

        // for idx = 0
        if (bin[0] == '0') {
            if (bin[1] == '0') {
                if (a + 1 == b) counter++;
            } else {
                if (a == b - 1) counter++;
            }
        } else {
            if (bin[1] == '0') {
                if (a - 1 == b) counter++;
            } else {
                if (a == b + 1) counter++;
            }
        }

        // for idx=size-1
        if (bin[size - 1] == '0') {
            if (bin[size - 2] == '0') {
                if (a == b + 1) counter++;
            } else {
                if (a - 1 == b) counter++;
            }
        } else {
            if (bin[size - 2] == '0') {
                if (a == b - 1) counter++;
            } else {
                if (a + 1 == b) counter++;
            }
        }
        cout << counter << endl;
    }
    // your code goes here
    return 0;
}
