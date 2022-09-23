class LRUCache {
   public:
    class Node {
       public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            Node* resNode = m[key_];
            int res = resNode->val;
            m.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existing = m[key];
            m.erase(key);
            deleteNode(existing);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */