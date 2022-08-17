/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings. There are various
applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise. boolean startsWith(String
prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise.
*/

struct Node {
    Node* links[26];
    bool flag;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (!temp->containsKey(word[i])) {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);  // move to next letter in the trie
        }
        temp->setEnd();
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (!temp->containsKey(word[i])) {
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->flag;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!temp->containsKey(prefix[i])) {
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */