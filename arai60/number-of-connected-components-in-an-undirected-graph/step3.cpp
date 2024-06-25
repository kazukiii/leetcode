class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency_list(n);
        vector<bool> visited(n, false);

        for (vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visitAllConnectedNodes(i, adjacency_list, visited);
            total++;
        }
        return total;
    }

private:
    void visitAllConnectedNodes(int node, vector<vector<int>>& adjacency_list, vector<bool>& visited) {
        visited[node] = true;
        for (int next_node : adjacency_list[node]) {
            if (visited[next_node]) continue;
            visitAllConnectedNodes(next_node, adjacency_list, visited);
        }
    }
};
