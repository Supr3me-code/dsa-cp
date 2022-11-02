// class Solution {
// public:
//     string getNextMutation(string a, string b){
//         for(int i=0;i<a.size();i++){
//             if(a[i]!=b[i]){
//                 a[i]=b[i];
//                 return a;
//             }
//         }
//         return a;
//     }

//     int minMutation(string start, string end, vector<string>& bank) {
//         set<string> s;
//         for(int i=0;i<bank.size();i++){
//             s.insert(bank[i]);
//         }

//         int result = 0;
//         while(start!=end){
//             start = getNextMutation(start, end);
//             if(s.find(start)==s.end()) return -1;
//             result++;
//         }
//         return result;
//     }
// };
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        // st holds all valid mutations
        unordered_set<string> st{bank.begin(), bank.end()};
        // if end mutaion is not in list return -1;
        if (!st.count(end)) return -1;
        // start BFS by pushing the starting mutation
        queue<string> Q;
        Q.push(start);
        int steps = 0, s;
        string cur, t;
        while (!Q.empty()) {
            s = Q.size();
            while (s--) {
                cur = Q.front();
                Q.pop();
                // If we reach end mutation
                if (cur == end) return steps;
                // We erase the cur mutation in order to avoid redundant
                // checking
                st.erase(cur);
                // as the length of mutation is 8 and it can take A,C,G,T
                // at each index we check the possibility of mutation by
                // replcaing it with A,C,G,T
                for (int i = 0; i < 8; i++) {
                    t = cur;
                    t[i] = 'A';
                    if (st.count(t)) Q.push(t);
                    t[i] = 'C';
                    if (st.count(t)) Q.push(t);
                    t[i] = 'G';
                    if (st.count(t)) Q.push(t);
                    t[i] = 'T';
                    if (st.count(t)) Q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};