#include <string>
#include <iostream>
using namespace std;

struct Motorcycle {
    int numCyl;
    string brand;
    string model;
};

void printMotorcycle(Motorcycle someBike);

int main() {
    Motorcycle aBike;
    printMotorcycle(aBike);
    // cout << aBike << endl; //wont compile until we do shit
}

void printMotorcycle(Motorcycle someBike) {
    cout << "Motorcycle: " << someBike.brand << ' ' << someBike.model << ' '
         << someBike.numCyl << endl;

}
