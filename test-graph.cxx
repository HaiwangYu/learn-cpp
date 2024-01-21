#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <string>

// Define a struct for the vertex properties
struct VertexProperties {
    size_t ident;
};

// Define the graph type with the vertex properties
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, VertexProperties> Graph;

int main() {
    // Create a graph object
    Graph g;

    // Add vertices to the graph with properties
    boost::add_vertex({1}, g);
    boost::add_vertex({2}, g);
    boost::add_vertex({3}, g);

    // Add edges to the graph
    boost::add_edge(0, 1, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(2, 0, g);

    // Print out the vertices and their properties
    Graph::vertex_iterator vi, vi_end;
    for (boost::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
        std::cout << "Vertex " << *vi << " ident: " << g[*vi].ident << std::endl;
    }

    // Print out the edges in the graph
    Graph::edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) {
        std::cout << *ei << std::endl;
    }

    return 0;
}
