class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    
    void deleteNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;
            
            deleteNode(resNode);
            addNode(resNode);
            
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        if (m.size() == capacity) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
        }
        
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */