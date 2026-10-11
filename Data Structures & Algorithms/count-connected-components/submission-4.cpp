class Solution {
    
public:
vector<bool> visit = vector<bool>(1000, false);

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                dfs(adj, node);
                res++;
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& adj, int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, nei);
            }
        }
    }
};