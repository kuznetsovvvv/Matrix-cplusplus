#pragma once
#include <iostream>
#include <string>
#define p 7
using namespace std;
class CMatrix {

public:
int rows, colls; // строки, столбцы
    int** matrix;
    CMatrix();
    CMatrix(int rws, int cls);
    CMatrix(int rws, int cls, int** v);
    CMatrix(const CMatrix& V);
    CMatrix(CMatrix&& V) noexcept;
    ~CMatrix();

    void Del();
    void print(string n);
    void ymench();
    void up();

    int Get_rows();
    int Get_colls();
    const void sum1(CMatrix& v);
    friend CMatrix operator +(CMatrix& v1, CMatrix& v2);
    CMatrix& operator =(CMatrix&& v) noexcept;
    CMatrix& operator=(const CMatrix& V);
};
