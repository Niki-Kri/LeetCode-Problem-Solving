class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_map<string, bool> visited;
    double dfs(string start, string end) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
            return -1.0;
        }  
        if (start == end) {
            return 1.0;
        }
        visited[start] = true;
        for (auto it = graph[start].begin(); it != graph[start].end(); it++) {
            string neighbor = it->first;
            double edgeWeight = it->second;
            if (visited[neighbor] == false) {
                double result = dfs(neighbor, end);
                if (result != -1.0) {
                    return result * edgeWeight;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();
        for (int i = 0; i < equations.size(); i++) {
            string node1 = equations[i][0];
            string node2 = equations[i][1];
            double weight = values[i];
            graph[node1][node2] = weight;
            graph[node2][node1] = 1.0 / weight;
        }
        vector<double> answer;
        for (int i = 0; i < queries.size(); i++) {
            string startNode = queries[i][0];
            string endNode = queries[i][1];
            visited.clear();
            double currentAnswer = dfs(startNode, endNode);
            answer.push_back(currentAnswer);
        }
        return answer;
    }
};