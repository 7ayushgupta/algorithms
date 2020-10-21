#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> color;
    void bfs(int u, int c) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        color[u] = c;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int col = color[node];
            for (int v : adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    color[v] = (col + 1) % 2;
                    q.push(v);
                }
            }
        }
    }

    int solve(vector<int>& source, vector<int>& dest, vector<int>& population) {
        adj.assign(population.size(), {});
        for (int i = 0; i < dest.size(); ++i) {
            adj[source[i]].push_back(dest[i]);
            adj[dest[i]].push_back(source[i]);
        }
        int res = 0;
        for (int i = 0; i < 2; ++i) {
            visited.assign(population.size(), false);
            color.assign(population.size(), 0);
            bfs(source[0], (i + 1) % 2);
            int sum = 0;
            for (int i = 0; i < population.size(); ++i) {
                ;
                if (color[i] == 0) {
                    sum += population[i];
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};
