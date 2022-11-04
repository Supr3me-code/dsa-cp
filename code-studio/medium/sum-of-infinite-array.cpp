
int valueAt(int x, int n, vector<int> &arr) {
    int relativeIdx;
    if (x % n != 0) {
        return arr[(x % n) - 1];
    }
    return arr[n - 1];
}

int sumTillX(int x, int sum, int n, vector<int> &arr) {
    int xsum = ((x / n) * sum);
    //     cout<<"INIT SUM: "<<xsum<<endl;
    //     cout<<"X: "<<x<<" N: "<<n<<endl;
    if (x % n != 0) {
        int Xindex = (x % n) - 1;
        for (int i = 0; i <= Xindex; i++) {
            xsum += arr[i];
            //             cout<<"Middle SUM: i="<<i<<" -> "<<xsum<<endl;
        }
    }
    return xsum;
}

vector<int> sumInRanges(vector<int> &arr, int n,
                        vector<vector<long long>> &queries, int q) {
    vector<int> result(q, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    for (int i = 0; i < q; i++) {
        int L = queries[i][0];
        int R = queries[i][1];

        int sumTillL = sumTillX(L, sum, n, arr);
        int sumTillR = sumTillX(R, sum, n, arr);
        sumTillL -= valueAt(L, n, arr);
        result[i] = sumTillR - sumTillL;
    }
    return result;
    // Write your code here
}