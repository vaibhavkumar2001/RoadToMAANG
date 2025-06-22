#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class Graph {
public:
    // adjacency list with pair: node -> (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adjList;

    // function to add edge (with weight)
    void addEdge(int u, int v, int wt, bool direction) {
        if (direction == 0) {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        } else {
            adjList[u].push_back({v, wt});
        }
    }

    // function to print adjacency list
    void PrintAdjList(int n) {
        for (int i = 0; i < n; i++) {
            cout << i << " -> { ";
            for (auto j : adjList[i]) {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << "}" << endl;
        }
    }

    // Dijkstra's algorithm
    void ShortestPathDijkstra(int src, int n) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto top = *(st.begin());
            int topDistance = top.first;
            int topNode = top.second;
            st.erase(st.begin());

            for (auto nbr : adjList[topNode]) {
                int nbrNode = nbr.first;
                int nbrDistance = nbr.second;

                if (topDistance + nbrDistance < dist[nbrNode]) {
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if (result != st.end()) {
                        st.erase(result);
                    }
                    dist[nbrNode] = topDistance + nbrDistance;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        // print result
        cout << "\nShortest distances from node " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << " -> Distance: " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;

    int nodes = 6;

    // addEdge(u, v, weight, direction)
    g.addEdge(0, 1, 4, 0);
    g.addEdge(0, 2, 3, 0);
    g.addEdge(1, 2, 1, 0);
    g.addEdge(1, 3, 2, 0);
    g.addEdge(2, 3, 4, 0);
    g.addEdge(3, 4, 2, 0);
    g.addEdge(4, 5, 6, 0);

    cout << "Adjacency List:\n";
    g.PrintAdjList(nodes);

    g.ShortestPathDijkstra(0, nodes);

    return 0;
}