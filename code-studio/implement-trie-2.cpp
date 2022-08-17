struct Node {
    Node* links[26];
    bool flag;
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void increasePrefix() { cntPrefix++; }
    void increaseEnd() { cntEndWith++; }
    void reducePrefix() { cntPrefix--; }
    void reduceEnd() { cntEndWith--; }
    int getEnd() { return cntEndWith; }
    int getPrefix() { return cntPrefix; }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(string& word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (!temp->containsKey(word[i])) {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string& word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
            } else {
                return 0;
            }
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string& word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
            } else {
                return 0;
            }
        }
        return temp->getPrefix();
        // Write your code here.
    }

    void erase(string& word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
                temp->reducePrefix();
            } else {
                return;
            }
        }
        return temp->reduceEnd();
        // Write your code here.
    }
};
