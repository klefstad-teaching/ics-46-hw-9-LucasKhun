#include "./dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int num_vertices = G.numVertices;
    vector<int> distances(num_vertices, INF);
    distances[source] = 0;
    vector<bool> visited(num_vertices, false);
    previous.assign(num_vertices, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, WeightComparator> pq;
    pq.push({source, 0});

    while(!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();
        int u = current.first;
        if(visited[u])
            continue;
        visited[u] = true;
        for(Edge e : G[u]){
            int v = e.dst;
            int weight = e.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    stack<int> reverse_path;
    int vertex = destination;
    while(vertex != -1){
        reverse_path.push(vertex);
        vertex = previous[vertex];
    }

    vector<int> path;
    while(!reverse_path.empty()){
        path.push_back(reverse_path.top());
        reverse_path.pop();
    }
    return path;
}

void print_path(const vector<int>& v, int total){
    for (int vert : v)
        cout << vert << " ";
    cout << "\nTotal cost is " << total << endl;
}