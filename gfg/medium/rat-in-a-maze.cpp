class Solution{
    public:
    
    void recur(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        string dir="DLRU";
        for(int k=0;k<4;k++){
            int nexti = i + di[k];
            int nextj = j + dj[k];
            if( nexti>=0 &&
                nextj>=0 &&
                nextj<n &&
                nexti<n &&
                !vis[nexti][nextj] &&
                a[nexti][nextj] == 1){
                    vis[i][j] = 1;
                    recur(nexti, nextj, a, n, ans, move + dir[k], vis, di, dj);
                    vis[i][j] = 0;
                }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) recur(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
        // Your code goes here
    }
};
