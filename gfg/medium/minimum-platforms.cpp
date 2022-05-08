class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
        sort(arr, arr+n);
        sort(dep, dep+n);

        int plat_needed = 1;
        int result = 1;
        int i = 1;
        int j = 0;

        while( i<n && j<n){
            if(arr[i]<=arr[j]){
                plat_needed++;
                i++;
            }
            else if(arr[i]>dep[j]){
                plat_needed--;
                j++;
            }

            result = max(result, plat_needed);
        }

        return result;
    }
} 