int Solution::solve(vector<int> &A, int B) {
    map<int, int> m;
    int count = 0;
    int xorr = 0;

    for(auto x:A){
        xorr ^= x;
        
        if(xorr == B){
            count++;
        }

        if(m.find(xorr^B)!=m.end()){
            count += m[xorr^B];
        }

        m[xorr] += 1;
        
    }

    return count;
}
