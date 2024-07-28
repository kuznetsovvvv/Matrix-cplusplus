#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include"cmatrix.h"
#define p 7
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    fstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error with file" << endl;
    }
    else {
        int r = 0, c = 0;
        inputFile >> r;
        inputFile >> c;

        int** matriza = new int* [r];

        for (int i = 0; i < r; i++) {
            matriza[i] = new int[c];
            for (int j = 0; j < c; j++) {
                inputFile >> matriza[i][j]; 
            }
        }
        CMatrix M1(r, c, matriza);
        CMatrix M2(r, c, matriza);
        CMatrix M3(r, c);
        CMatrix M4;
        M3 = M1 + M2;
        M1.print("M1");
        M3.print("M3");
        M4.print("M4");

        M1.sum1(M1);
        M1.print("M1");

        CMatrix M5 = M1;
        M5.print("M5");



        CMatrix M6 = M1 + M2;
        M6.print("M6");


        CMatrix M7(r, c);
        swap(M1, M7);
        M1.print("M1");
        M7.print("M7");
        M7 = M2;
        M7.print("M7");


        M7.ymench();
        M7.print("M7");

        M7.up();
        M7.print("M7");

        M7.up();
        M7.print("M7");
  cout << "M8:" << endl;
  CMatrix M8(r, c, matriza);
  cout << M8 << endl;

        inputFile.close();
    }
    return 0;

}
