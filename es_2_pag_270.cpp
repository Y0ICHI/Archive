#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    const int dim = 100;
    int i;
    int N[dim];
    srand(time(NULL));
    N[0] = rand() % 10;
    for (i = 1; i < dim; i++) {
        N[i] = N[i - 1] + rand() % 10;
    }
    for (i = 0; i < dim; i++) {
        cout << N[i] << " ";
    }
    return 0;
}

