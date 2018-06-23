#ifndef BFS_PRINT_H
#define BFS_PRINT_H

#include "../include/undirected_graph.h"

class breadthFirstSearch {
public:
    breadthFirstSearch(const undirected_graph& g);

    virtual ~breadthFirstSearch() = default;

    std::vector<int> traverse(int s);

    std::vector<int> distanceFromNode(int s);

    std::vector<std::vector<int>> connectivityInfo();

private:
    breadthFirstSearch() = default;

    std::map<int, std::set<int>> m_adjacencyList;
};

#endif /* ifndef BFS_PRINT_H */
