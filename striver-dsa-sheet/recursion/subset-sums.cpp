class Solution{
    public:
    void recur(int idx, int sum, vector<int> &sumArr, vector<int> &arr,int N){
        if(idx==N){
            sumArr.push_back(sum);
            return;
        }

        recur(idx+1,sum+arr[idx],sumArr,arr,N);
        recur(idx+1,sum,sumArr,arr,N);
    }

    public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> sumArr;
        recur(0,0,sumArr,arr,N);
        sort(sumArr.begin(), sumArr.end());
        return sumArr;
    }
}