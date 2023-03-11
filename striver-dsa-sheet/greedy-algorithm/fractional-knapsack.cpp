// Given weights and values of N items, we need to put these items in a knapsack
// of capacity W to get the maximum total value in the knapsack. Note: Unlike
// 0/1 knapsack, you are allowed to break the item.

class Solution {
   public:
    bool comparator(Item item1, Item item2) {
        double r1 = (double)item1.value / (double)item1.weight;
        double r2 = (double)item2.value / (double)item2.weight;
        return r1 > r2;
    }
    double franctionalKnapsack(int W, int arr[], int n) {
        double maxProfit = 0.0;
        int currentWeight = 0;
        sort(arr, arr + n, comparator);

        for (int i = 0; i < n; i++) {
            if (arr[i].weight + currentWeight <= W) {
                currentWeight += arr[i].weight;
                maxProfit += arr[i].value;
            } else {
                int remaining = W - currentWeight;
                maxProfit +=
                    (arr[i].value / (double)arr[i].weight) * (double)remaining;
                break;
            }
        }
        return maxProfit;
    }
}

struct Item {
    int value;
    int weight;
};
class Solution {
   public:
    bool static comp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalvalue +=
                    (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }

        return finalvalue;
    }
};