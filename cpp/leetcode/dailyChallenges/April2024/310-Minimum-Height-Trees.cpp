/*

https://leetcode.com/problems/minimum-height-trees/description/

*/

#include<vector>

using namespace std;

class Solution {
    void findFarthestNode(int node, int dist, int& endNode, int& endDist, vector<vector<int>>& graph, vector<bool>& vis) {

        vis[node] = true;

        for(auto& neighbor: graph[node]) {
            if(!vis[neighbor]) {
                if(endDist < dist+1) {
                    endDist = dist+1;
                    endNode = neighbor;
                }
                findFarthestNode(neighbor, dist+1, endNode, endDist, graph, vis);
            }
        }

        vis[node] = false;
    }

    bool findPath(int node, int endNode, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& path) {

        vis[node] = true;
        path.push_back(node);
        
        if(node == endNode) {
            return true;
        }

        for(auto& neighbor: graph[node]) {
            if(!vis[neighbor] && findPath(neighbor, endNode, graph, vis, path)) {
                return true;
            }
        }

        path.pop_back();
        vis[node] = false;
        return false;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());

        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int endNode1, dist1, endNode2, dist2;
        vector<bool> vis(n, false);

        vis[0] = true;
        findFarthestNode(0, 0, endNode1, dist1, graph, vis);
        vis[0] = false;

        vis[endNode1] = true;
        findFarthestNode(endNode1, 0, endNode2, dist2, graph, vis);
        vis[endNode1] = false;

        vector<int> path;
        findPath(endNode1, endNode2, graph, vis, path);

        int nodes = path.size();
        vector<int> roots;

        roots.push_back(path[nodes>>1]);
        if(path.size()%2 == 0) {
            roots.push_back(path[(nodes-1)>>1]);
        }

        return roots;
    }
};

int main() {
    return 0;
}