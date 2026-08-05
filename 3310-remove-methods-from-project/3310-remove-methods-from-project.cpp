class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Graph - Adjacency List
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);

        // Build Graph
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        // BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {

            int curr = que.front();
            que.pop();

            for (int &ngbr : adj[curr]) {

                inDegree[ngbr]--;

                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for (int i = 0; i < n; i++) {

            if (suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        if (cannotRemove) {

            vector<int> vec(n);

            for (int i = 0; i < n; i++) {
                vec[i] = i;
            }

            return vec;
        }

        return result;
    }
};