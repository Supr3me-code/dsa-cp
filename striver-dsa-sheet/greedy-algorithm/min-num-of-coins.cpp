// Given a value V, if we want to make a change for V cents, and we have an
// infinite supply of each of C = { C1, C2, .., Cm} valued coins, what is the
// minimum number of coins to make the change? If it’s not possible to make a
// change, print -1.

int main() {
    int V = 49;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    for (int i = n - 1; i >= 0; i--) {
        while (V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}