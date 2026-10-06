class Solution {
    vector<int> adj[1000];
    vector<bool> visited = vector<bool>(1000, false);

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Condition 1: no cycle
        if (dfs(0, -1))
            return false;

        // Condition 2: connected
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    bool dfs(int u, int par) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, u))
                    return true;
            }
            else if (v != par) {
                return true;
            }
        }

        return false;
    }
};