#ifndef A2_S2_PB_5_GAMEOFLIFE_H
#define A2_S2_PB_5_GAMEOFLIFE_H
#define SIZE1 10
#define SIZE2 20
#include "bits/stdc++.h"
using namespace std;
class Universe {
private:
    bool grid[SIZE1 + 2][SIZE2 + 2] = {{false}};
public:
    void initialize(string fileName);
    void nextGeneration();
    int countNeighbours(int x, int y);
    void run(int n);
    void reset();
    void display();
};

#endif //A2_S2_PB_5_GAMEOFLIFE_H