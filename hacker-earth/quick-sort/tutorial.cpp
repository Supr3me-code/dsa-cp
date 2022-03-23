#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start];
    for (int j = start + 1; j <= end; j++)
    {
        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]);
    return i - 1;
}

void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int piv_pos = partition(A, start, end);
        quick_sort(A, start, piv_pos - 1);
        quick_sort(A, piv_pos + 1, end);
    }
}

int main()
{
    int times;
    cin >> times;
    int nums[times - 1];
    for (int i = 0; i < times; i++)
    {
        cin >> nums[i];
    }
    quick_sort(nums, 0, times - 1);
    for (int i = 0; i < times; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}