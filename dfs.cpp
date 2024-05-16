#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to perform Depth First Search on a graph
// represented using an adjacency list
void dfs(const vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    stack<int> s;
    s.push(startNode);

    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;
        }

        // Push all unvisited adjacent vertices to the stack
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);

    cout << "Enter the edges (u v) one per line:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    vector<bool> visited(vertices, false);

    int startNode;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startNode;

    cout << "Depth First Traversal starting from vertex " << startNode << ": ";
    dfs(adjList, startNode, visited);
    cout << endl;

    return 0;
}

