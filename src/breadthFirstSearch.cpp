#include "../include/breadthFirstSearch.h"
#include <queue>

breadthFirstSearch::breadthFirstSearch(const undirected_graph& g)
{
    m_adjacencyList = g.getAdjacencyList();
}

std::vector<int> breadthFirstSearch::traverse(int s)
{
    int v;
    std::queue<int> bounds;
    std::vector<int> traversalOrder;
    // a safer compliant container alternative to `std::vector<bool>`
    std::map<int, bool> visited;
    for (auto node : m_adjacencyList) {
        visited[node.first] = false;
    }
    // mark the start vertex `s` as visited and insert it in a queue
    visited[s] = true;
    bounds.push(s);

    while (!bounds.empty()) {
        // remove the 1st node of the queue and print
        v = bounds.front();
        bounds.pop();
        traversalOrder.push_back(v);
        // for all vertices adjacent to v, check if they are visited
        for (auto i : m_adjacencyList[v]) {
            if (!visited[i]) {
                // mark `i` as visited and add it to the queue
                visited[i] = true;
                bounds.push(i);
            }
        }
    }
    return traversalOrder;
}

std::vector<int> breadthFirstSearch::distanceFromNode(int s)
{
    int n = m_adjacencyList.size();
    int inf = std::numeric_limits<int>::max();
    std::vector<int> dist(n, inf);
    dist[s] = 0;
    int v;
    std::queue<int> bounds;
    // a safer compliant container alternative to `std::vector<bool>`
    // a map also has one - one correspondence between node and bool
    // helps in cases when the starting node is not 0 based
    std::map<int, bool> visited;
    for (auto node : m_adjacencyList) {
        visited[node.first] = false;
    }
    // mark the start vertex `s` as visited and insert it in a queue
    visited[s] = true;
    bounds.push(s);

    while (!bounds.empty()) {
        // remove the 1st node of the queue and print
        v = bounds.front();
        bounds.pop();
        // for all vertices adjacent to v, check if they are visited
        for (auto i : m_adjacencyList[v]) {
            if (!visited[i]) {
                // mark `i` as visited and add it to the queue
                visited[i] = true;
                bounds.push(i);
                dist[i] = dist[v] + 1;
            }
        }
    }
    return dist;
}

std::vector<std::vector<int>> breadthFirstSearch::connectivityInfo()
{
    std::vector<std::vector<int>> connectedVertices;
    std::vector<int> temp;
    std::map<int, bool> visited;
    for (auto node : m_adjacencyList) {
        visited[node.first] = false;
    }
    int v;
    std::queue<int> bounds;

    //    for (int i = 0; i < n; ++i) {
    for (auto i : m_adjacencyList) {
        if (!visited[i.first]) {
            // if `i` is not visited, visit it and invoke the
            // BFS operation on this node.
            visited[i.first] = true;
            bounds.push(i.first);
            temp.clear();

            // BFS loop
            while (!bounds.empty()) {
                v = bounds.front();
                bounds.pop();
                temp.push_back(v);
                for (auto w : m_adjacencyList[v]) {
                    if (!visited[w]) {
                        visited[w] = true;
                        bounds.push(w);
                    }
                }
            }
            connectedVertices.emplace_back(temp);
        }
    }

    return connectedVertices;
}
