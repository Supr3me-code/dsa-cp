#include <iostream>
using namespace std;

int costOfTravel(int n, int x1, int y1, int x2, int y2) {
    int first = min(x2, n - x2 + 1);
    int second = min(y2, n - y2 + 1);
    int third = min(x1, n - x1 + 1);
    int forth = min(y1, n - y1 + 1);

    int finalX = min(third, forth);
    int finalY = min(second, first);
    finalX = finalX + finalY;
    return min(abs(x2 - x1) + abs(y2 - y1), finalX);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        cout << costOfTravel(n, x1, y1, x2, y2) << endl;
    }
    // your code goes here
    return 0;
}
