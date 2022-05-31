bool isSafe(vector<int> &A, int m, int n, int mid){
    int numberOfStudents = 1;
    int sum = 0;

    for(int i=0;i<n;i++){
        if(A[i]>mid) return false;

        if(A[i]+sum > mid){
            numberOfStudents++;
            sum = A[i];

            if(numberOfStudents>m) return false;
        }else{
            sum+=A[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();

    if(n<B)
        return -1;

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
    }

    int start = 0;
    int end = sum;
    int result;
    while(start<=end){
        int mid = (start + end)/2;
        if(isSafe(A,B,n,mid)){
            result = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return result;
}
