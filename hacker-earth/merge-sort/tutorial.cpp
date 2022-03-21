#include <iostream>
using namespace std;
typedef long long int ll;

void merge(ll arr[], ll start, ll mid, ll end)
{
    ll p = start;
    ll q = mid + 1;
    ll aux[end - start + 1];
    ll z = 0;

    for (ll i = start; i < end; i++)
    {
        if (p > mid)
        {
            aux[z++] = arr[q++];
        }
        else if (q > end)
        {
            aux[z++] = arr[p++];
        }
        else if (arr[p] < arr[q])
        {
            aux[z++] = arr[p];
        }
        else
        {
            aux[z++] = arr[q];
        }
    }

    for (ll i = 0; i < z; i++)
    {
        arr[start++] = aux[i];
    }
}

void merge_sort(ll arr[], ll start, ll end)
{
    if (start < end)
    {
        ll mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll start = 0;
    ll end = n - 1;
    merge_sort(arr, start, end);

    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}