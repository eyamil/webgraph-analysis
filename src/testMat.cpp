#include "Graph.hpp"

void testMat(int n) {

    nxnMatrix mat(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat(i,j) = n*i+j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mat(i,j) != n*i+j) {
                cout << "mat(" << i << "," << j << ") = " << mat(i,j) << endl;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 100; i++) {
        testMat(i);
    }
}
