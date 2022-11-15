#include "GameOfLife.h"
#include "bits/stdc++.h"
using namespace std;

//initializes the matrix

void Universe::initialize(string fileName1) {
    fstream file;
    file.open(fileName1);
    for(int i=1; i <SIZE1+1; i++){
        for (int j=1; j<SIZE2+1; j++){
            if(grid[i][j]){
                grid[i][j] = "X ";
            } else{
                grid[i][i] ="O ";
            }
        }
    }
    file.close();
    display();
}

//calculates the next generation of cells that are either alive or dead

void Universe::nextGeneration(){
    bool new_grid[SIZE1 + 2][SIZE2 + 2] = {{false}};
    for(int i=1; i <SIZE1+1; i++){
        for (int j=1; j<SIZE2+1; j++){
            int neighbours = countNeighbours(i,j);
            if (grid[i][j]){
                if (neighbours == 2 or neighbours == 3){
                    new_grid[i][j] = true;
                } else{
                    new_grid[i][j] = false;
                }
            } else{
                if (neighbours == 3){
                    new_grid[i][j] = true;
                }
            }
        }
    }
    for(int i=1; i <SIZE1+1; i++){
        for (int j=1; j<SIZE2+1; j++){
            new_grid[i][j] = grid[i][j];
        }
    }
    display();
}

//counts the number of neighbours to check if the cell will be alive or dead in the next generation

int Universe::countNeighbours(int x, int y){
    int res=-grid[x][y];
    for(int i=x-1; i <=  x+1; i++){
        for(int j=x-1; j <= x+1; j++) {
            res += grid[i][j];
        }
    }
    return res;
}

//runs the games

void Universe::run(int n) {
    for (int i = 0; i < n; i++) {
        system("cls");
        cout << "Generation: " << i << "/" << n << endl;
        system("pause");
        nextGeneration();

    }
}

//gives the user the option to reset the matrix back again

void Universe::reset() {
    for(int i=1; i <SIZE1+1; i++){
        for (int j=1; j<SIZE2+1; j++){
            grid[i][j] = false;
        }
    }
}

//displays the matrix

void Universe::display() {
    for(int i=1; i <SIZE1+1; i++){
        for (int j=1; j<SIZE2+1; j++){
            if (grid[i][j]){
                cout <<'n' ;
            } else{
                cout << '0';
            }
        }
        cout << endl;
    }
    cout << endl;

}
