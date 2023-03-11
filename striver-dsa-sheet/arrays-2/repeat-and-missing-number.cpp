// There are certain problems which are asked in the interview to also check how
// you take care of overflows in your problem.

// This is one of those problems.

// Please take extra care to make sure that you are type-casting your ints to
// long properly and at all places. Try to verify if your solution works if
// number of elements is as large as 105

vector<int> missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();
    long long int S = (len * (len + 1)) / 2;
    long long int P = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++) {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (S + P / S) / 2;
    repeating = missingNumber - S;
    vector<int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}