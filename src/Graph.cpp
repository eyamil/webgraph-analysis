#include "Graph.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

/* Add an edge to the node: 
 * to : the node to which the edge goes */
void Node::addEdge(int to) {
    edges.insert(to);
    outdegree++;
}

/* Check if there is an edge from this node to another
 * to : the node to which the edge should go */
bool Node::isEdge(int to) {
    return(edges.find(to) != edges.end());
}

/* Node Constructor: */
Node::Node(int id) : id(id), outdegree(0) {}

/* Node Destructor: */
Node::~Node(void) {}

/* Matrix Constructor: */
nxnMatrix::nxnMatrix(int n) : n(n), array(new double[n*n]) {}

/* Matrix Destructor: */
nxnMatrix::~nxnMatrix() {
    delete[] array;
}

const double& nxnMatrix::operator()(int nrow, int ncol) {
    return(array[n * nrow + ncol]);
}

/* Graph Constructor: */
Graph::Graph(void) {}

/* Graph Destructor: */
Graph::~Graph(void) {
    for (auto itr : vertices) {
        delete itr.second;
    }
    /*if (mat != nullptr) {
        delete mat;
    }*/
}

/* Add node to graph: 
 * node : pointer to the node to add to the graph */
void Graph::addNode(Node * node) {
    vertices[node -> id] = node;
}

/* Add edge to graph: 
 * from : id of the node from which the edge leaves
 * to : id of the node where the edge terminates */
void Graph::addEdge(int from, int to) {
    Node * node = vertices[from];
    node -> addEdge(to);
}

/* Check if two vertices define an edge:
 * from : id of the node from which the edge leaves
 * to : id of the node where the edge terminates */
bool Graph::isEdge(int n1, int n2) {
    Node * node = vertices[n1];
    return(node -> isEdge(n2));
}

/* Read in relationships from an inputfile to create a graph */
bool Graph::loadFromFile(const char* in_filename) {
  ifstream infile(in_filename);

  while (infile) {
    string s;
    if (!getline(infile, s)) break;

    istringstream ss(s);
    vector<string> record;

    while (ss) {
      string s;
      if (!getline(ss, s, ' ')) break;
      record.push_back(s);
    }

    if (record.size() != 2) {
      continue;
    }

    string::size_type size;
    int n1 = stoi(record[0], &size);
    int n2 = stoi(record[1], &size);
    if (vertices[n1] == nullptr) {
        Node * node = new Node(n1);
        addNode(node);
    }
    if (vertices[n2] == nullptr) {
        Node * node = new Node(n2);
        addNode(node);
    }
    Graph::addEdge(n1, n2);
      
  }

  if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }

  infile.close();
  return true;
}
