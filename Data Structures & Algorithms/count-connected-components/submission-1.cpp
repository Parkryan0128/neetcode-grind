class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        int count = 0;
        for (int i=0; i < n; i++) {
            if (!visited.count(i)) {
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }

    void dfs(int node, vector<vector<int>> & adj, unordered_set<int> & visited) {
        if (visited.count(node)) {
            return;
        }

        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, adj, visited);
            }
        }

        return;
    }
};
