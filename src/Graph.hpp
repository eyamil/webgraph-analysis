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
        int outdegree;
        double rank;

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

class nxnMatrix {
    public:
        const int n;
        double * const array;

        /* Default constructor: 
         * n: size of the (square) matrix */
        nxnMatrix(int n);

        /* Destructor: */
        ~nxnMatrix(void);

        /* Array element access: 
         * nrow: row number of the matrix element
         * ncol: column number of the matrix element */
        double & operator()(int nrow, int ncol);
        
        /* Array element access operator: 
         * nrow: row number of the matrix element
         * ncol: column number of the matrix element */
        double get(int nrow, int ncol) const;

        /* Matrix multiply an array by this matrix:
         * v: vector to multiply */
        void apply(vector<double> & v);

        /* Compute magnitude of a vector: */
        double magnitude(vector<double> & v);

        /* Compute the eigenvector of the matrix by power approximation: */
        vector<double> computePrincipalEigenvector();
};

class Graph {
    public:
        unordered_map<int, Node*> vertices;
	nxnMatrix * matrix;

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

	/* Build the stochastic matrix 
         * resistance: Probability a user will leave the page */
        void buildMatrix(double moveP);
};

#endif
