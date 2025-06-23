#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        // 0 -> undirected, 1 -> directed
        adjList[u].push_back(v);
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void FindBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int, bool>& visited) {
        visited[src] = true;
        tin[src] = low[src] = timer++;
        
        for (auto nbr : adjList[src]) {
            if (nbr == parent) continue;

            if (!visited[nbr]) {
                FindBridges(nbr, src, timer, tin, low, visited);
                low[src] = min(low[src], low[nbr]);

                // Check if it's a bridge
                if (low[nbr] > tin[src]) {
                    cout << src << " -- " << nbr << " is a Bridge" << endl;
                }
            } else {
                // Back edge
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 0, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(4, 5, 0); // This edge is a bridge

    int n = 6; // number of nodes
    int timer = 0;
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.FindBridges(i, -1, timer, tin, low, visited);
        }
    }

    return 0;
}
