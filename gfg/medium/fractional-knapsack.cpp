class Solution{
    public:
    bool comparator(Item item1, Item item2){
        double r1 = (double)item1.value/ (double)item1.weight;
        double r2 = (double)item2.value/ (double)item2.weight;
        return r1>r2;
    }
    double franctionalKnapsack(int W, int arr[], int n){
        double maxProfit = 0.0;
        int currentWeight = 0;
        sort(arr, arr+n, comparator);

        for(int i=0;i<n;i++){
             if(arr[i].weight+currentWeight<=W){
                 currentWeight+= arr[i].weight;
                 maxProfit += arr[i].value;
             }else{
                 int remaining = W - currentWeight;
                 maxProfit += (arr[i].value/(double)arr[i].weight) * (double)remaining;
                 break;
             }
        }
        return maxProfit;
    }
}