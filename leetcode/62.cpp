//-------brute force

/*class Solution {
public:
    int sum = 0;
    
    int totalPaths(int i, int j, int m, int n){
        
        if(i>m || j>n){
            return 0;
        }
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        sum = totalPaths(i+1,j,m,n) + totalPaths(i,j+1,m,n);
        
        return sum;
    }
    
    
    int uniquePaths(int m, int n) {
        int result = totalPaths(0,0,m,n);
        
        return result;
    }
};*/

//----OPTIMAL SOLUTION

class Solution {
public:
    
    //ans = (n+m-2)C(m-1) or (n+m-2)C(n-1) -> total steps to be taken = n-1 + m-1 = n+m-2
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int R = m-1;
        double res = 1;
        
        for(int i=1;i<=R;i++){
            res = res * (N-R+i)/i;
        }
        return (int)res;
        
    }
};