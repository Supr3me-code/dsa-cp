#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    while (n--) {
        int know = 0;
        for (int i = 0; i < 3; i++) {
            int x;
            cin >> x;
            if (x == 1) know++;
        }
        if (know >= 2) result++;
    }
    cout << result << endl;
    return 0;
}