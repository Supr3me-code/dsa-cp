#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        int temp = arr2[i];
        int j = i;
        while (j > 0 && temp < arr2[j - 1])
        {
            arr2[j] = arr2[j - 1];
            j--;
        }
        arr2[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        int number = arr1[i];
        for (int j = 0; j < n; j++)
        {
            if (arr2[j] == number)
            {
                cout << j + 1 << " ";
            }
        }
    }
    cout << endl;
    return 0;
}