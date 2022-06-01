struct Node{
    Node* links[26];
    bool flag;
    bool containsKey(char ch){
        return links[ch - 'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.length();i++){
            if(!temp->containsKey(prefix[i])){
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