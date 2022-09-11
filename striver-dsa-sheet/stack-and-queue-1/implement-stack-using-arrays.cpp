#include <iostream>
using namespace std;

void addToStack(vector<int> &st, int num) {}

int main() {
    int size;
    cout << "enter the size of the stack" << endl;
    cin >> size;
    vector<int> st(size);
    cout << "List of operations:\n1. add a number\n2. display top\n3.remove "
            "topmost number\n4. print stack (top first)\n";
    int response;
    cin >> response;
    switch (response) {
        case 1: {
            cout << "enter the number to be added" << endl;
            int num;
            cin >> num;
            addToStack(st, num);
            break;
        }
        case 2: {
            cout << diplayTop() << endl;
            break;
        }
        case 3: {
            cout << removeTop() << endl;
            break;
        }
        case 4: {
            displayStack();
            break;
        }
    }
    return 0;
}