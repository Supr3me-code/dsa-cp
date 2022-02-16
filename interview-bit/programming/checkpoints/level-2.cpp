//Print concentric rectangular pattern in a 2d matrix. 
#include <iostream>
using namespace std;

vector<vector<int>> prettyPrint(int A) {
    int n = (2*A)-1;                                            //dimension of the matrix
    vector<vector<int>> result(n, vector<int>(n,0));            
   
    
    for(int i=0;i<A;i++){
        for(int j=i; j<n-i; j++){        
            result[i][j]= A-i;
            result[j][n-1-i]= A-i;
            result[n-1-j][i]= A-i;
            result[n-1-i][n-1-j]= A-i;          
        }
    }

    return result;
}
