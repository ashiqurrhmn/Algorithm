#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void bfs(const vector<vector<int>>& adjlist, int startNode, vector<bool>& visited)
{
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout<<currentNode<<" ";
        for(int neighbor : adjlist[currentNode])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adjlist, int u, int v)
{
    adjlist[u].push_back(v);
}
int main()
{
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> startNode;

    cout << "Breadth First Traversal starting from vertex " << startNode << ": ";
    bfs(adjList, startNode, visited);
    cout << endl;

    return 0;
}
