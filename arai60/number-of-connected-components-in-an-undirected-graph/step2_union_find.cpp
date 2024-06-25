class UnionFind {
private:
    vector<int> parents_;

public:
    UnionFind(int n) {
        parents_.resize(n, -1);
    }

    int find(int x) {
        if (parents_[x] == -1) return x;
        return parents_[x] = find(parents_[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parents_[x] = y;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (vector<int> edge : edges) {
            uf.unite(edge[0], edge[1]);
        }

        unordered_set<int> unique_groups;
        for (int i = 0; i < n; i++) {
            unique_groups.insert(uf.find(i));
        }
        return unique_groups.size();
    }
};
