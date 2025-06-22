#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void addEdge(vector<int>adj[],int u,int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}
void TopologicalBFS(int n,vector<int>adj[],vector<int>&ans) {
    unordered_map<int,int>indegree;
    queue<int>q;
    //phele main indegree wala map tyaar kar loonga
    for(int i = 0;i < n;i++) {
        for(auto nbr : adj[i]) {
            indegree[nbr]++;
        }
    }
    //mera map tyaar hogaya h 
    // AB main check jiska bhi indegree 0 hoga usko queue mein push kardoonga
    for(int i = 0;i < n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    //AB mera mainn logic start hoga yaha se 
    while(!q.empty()) {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();
        for(auto nbr : adj[frontNode]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }    
}
vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int>ans;
    TopologicalBFS(V,adj,ans);
    return ans;
}

int main() {
}