#include <iostream>
#include "GameOfLife.cpp"

int main() {
    int n, choice;
    string filename;
    cout << "Please enter the number of times you want to run your program and the file name: ";
    cin >> n >> filename;
    Universe universe;
    universe.initialize(filename);
    universe.run(n);
    cout << "Do you want to reset game? Enter 1 if yes and 0 if no: ";
    cin >> choice;
    if (choice == 1){
        universe.reset();
    }
}
