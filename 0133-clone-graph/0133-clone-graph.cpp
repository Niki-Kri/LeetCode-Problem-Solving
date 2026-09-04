class Solution {
    unordered_map<Node*, Node*> clonedNodes;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        }
        Node* clone = new Node(node->val);
        clonedNodes[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone;
    }
};