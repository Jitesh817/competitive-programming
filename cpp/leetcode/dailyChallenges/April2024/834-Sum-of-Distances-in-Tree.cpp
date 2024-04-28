/*

https://leetcode.com/problems/sum-of-distances-in-tree/description/

*/

#include<vector>

using namespace std;

class Solution {
    int nodes;
    vector<vector<int>> graph;
    vector<int> count;
    vector<int> dist;

    void dfs(int node, int parent) {

        for(int neighbor: graph[node]) {
            if(neighbor == parent) {
                continue;
            }

            dfs(neighbor, node);
            count[node] += count[neighbor];
            dist[node] += dist[neighbor] + count[neighbor];
        }

        count[node]++;
    }

    void dfsAdjust(int node, int parent) {

        for(int neighbor: graph[node]) {
            if(neighbor == parent) {
                continue;
            }

            dist[neighbor] = dist[node] - count[neighbor] + nodes - count[neighbor];
            dfsAdjust(neighbor, node);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nodes = n;
        graph.resize(n);
        count.resize(n);
        dist.resize(n);

        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        dfsAdjust(0, -1);

        return dist;
    }
};

int main() {
    return 0;
}