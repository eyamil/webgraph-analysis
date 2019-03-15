#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.hpp"

using namespace std;

void usage(char* program_name) {
  cerr << program_name << " called with incorrect arguments." << endl;
  cerr << "Usage: " << program_name
       << " web_graph_file moveP output_file"
       << endl;
  cerr << "moveP is the likelihood that someone browses away" << endl;
  exit(-1);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }
    
    char* graph_filename = argv[1];
    char* output_filename = argv[3];
    istringstream ss(argv[2]);

    // Check ss format, make int
    vector<string> record;

    while (ss) {
      string s;
      if (!getline(ss, s, ' ')) break;
      record.push_back(s);
    }

    string::size_type size;
    double p = stod(record[0], &size);

    // Setup:
    Graph graph;
    graph.loadFromFile(graph_filename);
    ofstream output;
    output.open(output_filename);
   
    // Start to compute, with initial eigenvector magnitude of 10:
    graph.buildMatrix(p);
    graph.computeRanks(1000.0);

    for (auto i : graph.pagerank) {
        output << i << endl;
    }
    
    output.close();
}
