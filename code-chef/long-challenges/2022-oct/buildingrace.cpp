#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        float a, b, x, y;
        cin >> a >> b >> x >> y;
        float chef = a / x;
        float chefina = b / y;
        if (chef > chefina) {
            cout << "Chefina" << endl;
        } else if (chef < chefina) {
            cout << "Chef" << endl;
        } else {
            cout << "Both" << endl;
        }
    }
    return 0;
}
