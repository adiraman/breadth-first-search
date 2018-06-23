#include "../include/breadthFirstSearch.h"
#include "../include/undirected_graph.h"

template <typename T>
void printVec(const T& elems)
{
    for (auto i : elems) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return;
}

int main()
{
    undirected_graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(4, 1);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(7, 3);
    g.addEdge(4, 7);
    g.addEdge(7, 5);
    g.addEdge(6, 7);
    std::cout << "           Input Graph          " << std::endl;
    std::cout << g << std::endl;
    g.writeDot("graph.dot");

    breadthFirstSearch bfs(g);

    std::cout << " Traversal from node 3 " << std::endl;
    auto t1 = bfs.traverse(3);
    printVec(t1);
    std::cout << " distances from node 3 " << std::endl;
    printVec(bfs.distanceFromNode(3));

    std::cout << " Traversal from node 5 " << std::endl;
    auto t2 = bfs.traverse(5);
    printVec(t2);
    std::cout << " distances from node 5 " << std::endl;
    printVec(bfs.distanceFromNode(5));

    std::cout << " Traversal from node 0 " << std::endl;
    auto t3 = bfs.traverse(0);
    printVec(t3);
    std::cout << " distances from node 0 " << std::endl;
    printVec(bfs.distanceFromNode(0));

    undirected_graph g1;
    g1.addEdge(1, 3);
    g1.addEdge(1, 5);
    g1.addEdge(3, 5);
    g1.addEdge(5, 7);
    g1.addEdge(5, 9);
    g1.addEdge(2, 4);
    g1.addEdge(6, 8);
    g1.addEdge(6, 10);
    g1.addEdge(8, 10);
    g1.writeDot("graph2.dot");
    std::cout << "Input graph 2" << std::endl;
    std::cout << g1 << std::endl;

    breadthFirstSearch bfs1(g1);
    auto conn = bfs1.connectivityInfo();

    std::cout << "    Connected Components  " << std::endl;
    for (auto i : conn) {
        for (auto j : i) {
            std::cout << j << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
