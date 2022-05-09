class Solution{
    public:
    bool comparator(Job job1, Job job2){
        return (job1.profit > job2.profit);ß
    }
    vector<int> JobScheduling(Job arr[], int n){
        vector<int> result;
        sort(arr, arr+n, comparator);
        int maxi = arr[0].dead;
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        int slot[maxi + 1];
        for(int i=0;i<n;i++){
            slot[i] = -1;
        }
        int count = 0;
        int totalProfit = 0;

        for(int i=0;i<n;i++){
            for(int j = arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j] = i;
                    count++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        result.push_back(count);
        result.push_back(totalProfit);
        return result;
    }
};