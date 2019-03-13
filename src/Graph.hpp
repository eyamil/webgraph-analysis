#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
    public:
        const int id;
        unordered_set<int> edges;

        /* Default constructor: */
        Node(int id);

        /* Destructor: */
        ~Node(void);

        /* Add an edge to the node:
         * to: id of the node to which the edge goes */

        void addEdge(int to);

        /* Check if an edge from this node to another exists:
         * to: id of the node to which the edge goes */

        bool isEdge(int to);
};

class Graph {
    public:
        unordered_map<int, Node*> vertices;

        /* Default constructor: */
        Graph(void);

        /* Destructor: */
        ~Graph(void);

        /* Add node to graph:
         * node: pointer to the node to add to the graph */
        void addNode(Node * node);

        /* Add edge to graph: 
         * from: node where the edge originates
         * to: node where the edge terminates */
        void addEdge(int from, int to);

        /* Check if an edge is present in the graph:
         * from: node where the edge should originate
         * to: node where the edge should terminate */
        bool isEdge(int from, int to);

        /* Load graph data from a file:
         * in_filename: the input file name */
        bool loadFromFile(const char* in_filename);
};
