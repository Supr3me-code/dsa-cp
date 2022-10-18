#include <bits/stdc++.h>
void sortStack(stack<int> &stack) {
    vector<int> arr;
    while (!stack.empty()) {
        arr.push_back(stack.top());
        stack.pop();
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        stack.push(arr[i]);
    }
    // Write your code here
}

//--------------------------------------------------

#include <bits/stdc++.h>
void sortedInsert(stack<int> &stack, int num) {
    if (stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(top);
}

void sortStack(stack<int> &stack) {
    if (stack.empty()) return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);
    sortedInsert(stack, num);
    // Write your code here
}