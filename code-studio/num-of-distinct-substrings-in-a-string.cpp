struct Node {
    Node* links[26];

    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
};

int countDistinctSubstrings(string& s) {
    int result = 0;
    int n = s.size();
    Node* root = new Node();
    for (int i = 0; i < n; i++) {
        Node* temp = root;
        for (int j = i; j < n; j++) {
            if (!temp->containsKey(s[j])) {
                result++;
                temp->put(s[j], new Node());
            }
            temp = temp->get(s[j]);
        }
    }
    return result + 1;

    //    Write your code here.
}