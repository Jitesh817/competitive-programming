/*

https://leetcode.com/problems/find-if-path-exists-in-graph/description/

*/

#include<vector>

using namespace std;

class DisjoinSet {

    vector<int> parent;

public:
    DisjoinSet(int n) {
        parent = vector<int>(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool joinNodes(int node1, int node2) {
        int p1 = findParent(node1);
        int p2 = findParent(node2);

        if(p1 == p2) {
            return false;
        }

        parent[p1] = p2;
        return true;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        DisjoinSet disjointSet = DisjoinSet(n);

        for(auto& edge: edges) {
            disjointSet.joinNodes(edge[0], edge[1]);
        }

        return disjointSet.findParent(source) == disjointSet.findParent(destination);
    }
};

int main() {
    return 0;
}