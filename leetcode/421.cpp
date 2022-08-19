class Solution {
   public:
    struct Node {
        Node* links[2];
        bool flag;

        bool containsKey(int bit) { return links[bit] != NULL; }
        Node* get(int bit) { return links[bit]; }
        void put(int bit, Node* node) { links[bit] = node; }
    };

    class Trie {
       private:
        Node* root;

       public:
        Trie() { root = new Node(); }

        void insert(int num) {
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!temp->containsKey(bit)) {
                    temp->put(bit, new Node());
                }
                temp = temp->get(bit);
            }
        }

        int getMax(int num) {
            Node* temp = root;
            int maxNum = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (temp->containsKey(!bit)) {
                    maxNum = maxNum | (1 << i);
                    temp = temp->get(1 - bit);
                } else {
                    temp = temp->get(bit);
                }
            }
            return maxNum;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for (int i = 0; i < n; i++) {
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, trie.getMax(nums[i]));
        }
        return maxi;
    }
};