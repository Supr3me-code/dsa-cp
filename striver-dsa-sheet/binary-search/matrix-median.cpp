/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int r = A.size();
    int c = A[0].size();

    for(int i=0;i<r;i++){ 
        if(maxi<A[i][0])
            maxi = A[i][0];  // calculating the maximum number in the matrix

        if(mini>A[i][c-1])
            mini = A[i][c-1]; // calculating the minimum number in the matrix
    }

    int desired = (r*c-1)/2; // the desired number will have this much elements smaller than it (half the total excluding itself)

    while(mini<maxi){
        int mid = mini + (mini+maxi)/2;
        int place = 0; // number of elements smaller
        for(int i=0;i<r;i++){
            // for(int j=0;j<c;j++){
            //     if(A[i][j]>mid)
            //         break;
            //     place++;
            // }
            place += upper_bound(A[i], A[i]+c, mid) - A[i]; // calculates the place of an element in an array, basically calculates the number of elements smaller than A[i]
        }
        if(desired<place)
            maxi = mid;
        else
            mini = mid+1;
    }

    return mini;
}
