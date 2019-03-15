#include "Graph.hpp"

void testIndices(int n) {

    nxnMatrix mat(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat(i,j) = (double) (n*i+j);
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

void testMult(int n) {

    nxnMatrix mat(n);
    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = (double) i;
    }
    for (int i = 0; i < n; i++) {
        mat(i,i) = (double) i;
    }
    mat.apply(vec);
    for (int i = 0; i < n; i++) {
        if (vec[i] != (double) (i*i)) {
            cout << "oh crap" << endl;
        }
    }

}

int main() {
    for (int i = 0; i < 100; i++) {
        testIndices(i);
    }
    for (int i = 0; i < 100; i++) {
        testMult(i);
    }
}
