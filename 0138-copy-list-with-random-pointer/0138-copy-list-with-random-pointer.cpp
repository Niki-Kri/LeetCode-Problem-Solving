/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        while (current != NULL) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while (current != NULL) {
            Node* newNode = nodeMap[current];
            newNode->next = nodeMap[current->next];
            newNode->random = nodeMap[current->random];
            current = current->next;
        }
        return nodeMap[head];
    }
};