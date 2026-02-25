//UID:24BCS10773

class Solution {
  public:
  int root(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = root(parent[node], parent);
    }
    void unionBySize(int a, int b, vector<int>& parent, vector<int>& size) {
        a = root(a, parent);
        b = root(b, parent);

        if (a == b) return;

        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(),
             [](vector<int>& x, vector<int>& y) {
                 return x[2] < y[2];
             });

        vector<int> parent(V);
        vector<int> size(V, 1);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        int totalWeight = 0;

        for (auto &e : edges) {
            int a = e[0];
            int b = e[1];
            int wt = e[2];

            if (root(a, parent) != root(b, parent)) {
                totalWeight += wt;
                unionBySize(a, b, parent, size);
            }
        }

        return totalWeight;
    }
};
