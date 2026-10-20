#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    int vertices;
    vector<int>* adj;

    Graph(int totalVertices)
    {
        vertices = totalVertices;
        adj = new vector<int>[vertices];
    }

    void addEdge(int first, int second)
    {
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    void DFS(int current, bool visited[])
    {
        visited[current] = true;
        cout << current << " ";

        for(int neighbour : adj[current])
        {
            if(!visited[neighbour])
            {
                DFS(neighbour, visited);
            }
        }
    }

    void BFS(int start)
    {
        bool* visited = new bool[vertices];

        for(int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for(int neighbour : adj[current])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        delete[] visited;
    }

    ~Graph()
    {
        delete[] adj;
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph city(vertices);

    cout << "Enter edges:" << endl;

    for(int i = 0; i < edges; i++)
    {
        int first, second;
        cin >> first >> second;
        city.addEdge(first, second);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bool* visited = new bool[vertices];

    for(int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }

    cout << "DFS Traversal: ";
    city.DFS(start, visited);
    cout << endl;

    delete[] visited;

    cout << "BFS Traversal: ";
    city.BFS(start);
    cout << endl;

    return 0;
}