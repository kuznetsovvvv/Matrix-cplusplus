#include "Cmatrix.h"

   CMatrix::CMatrix()
    {
        rows = 0;
        colls = 0;
        matrix = nullptr;
    }

   CMatrix::CMatrix(int rws, int cls)
    {
        this->rows = rws;
        this->colls = cls;
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[colls];
        }
    }

   CMatrix::CMatrix(int rws, int cls, int** v)
    {
        this->rows = rws;
        this->colls = cls;
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[colls];
            for (int j = 0; j < colls; j++)
            {
                matrix[i][j] = v[i][j] % p;
            }
        }
    }

   void CMatrix::Del()
    {
        for (int z = 0; z < rows; z++)
            delete[] matrix[z];

        delete[] matrix;
    }




   CMatrix::CMatrix(const CMatrix& V) {// копирование

        rows = V.rows;
        colls = V.colls;
        matrix = new  int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[colls];
            for (int j = 0; j < colls; j++)
            {
                matrix[i][j] = V.matrix[i][j];
            }
        }
        cout << "CMatrix(const CMatrix & V) " << endl;
    }



   CMatrix::CMatrix(CMatrix&& V) noexcept {//перемещение     

        swap(rows, V.rows);
        swap(colls, V.colls);
        swap(matrix, V.matrix);
        cout << "CMatrix(CMatrix&& V)" << endl;
    }



    int CMatrix::Get_rows() {
        return rows;
    }

    int CMatrix::Get_colls() {
        return colls;
    }


    const void CMatrix::sum1(CMatrix& v) {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colls; j++)
            {
                v.matrix[i][j] += 1;
            }
        }

    }







    CMatrix operator +(CMatrix& v1, CMatrix& v2) {
        int m1 = v1.Get_rows();//строки
        int n1 = v1.Get_colls();//столбцы

        int m2 = v2.Get_rows();
        int n2 = v2.Get_rows();

        if (m1 == m2 && n1 == n2) {
            int** temp = new  int* [m1];
            for (int i = 0; i < m1; i++)
            {
                temp[i] = new int[n1];
                for (int j = 0; j < n1; j++)
                {
                    temp[i][j] = (v1.matrix[i][j] + v2.matrix[i][j]) % p;
                }

            }
            cout << "operator+" << endl;
            return CMatrix(m1, n1, temp);
        }
        else {


            cout << "Матрицы не соразмерны, лишние строки и столбцы не складываются соответственно с элементами!" << endl;
            return CMatrix(0, 0);
        }

    }




   CMatrix& CMatrix::operator =(CMatrix&& v) noexcept {
        if (this == &v) {
            return *this;
        }

        Del();


        swap(rows, v.rows);
        swap(colls, v.colls);
        matrix = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[colls];
            for (int j = 0; j < colls; j++)
            {
                swap(matrix[i][j], v.matrix[i][j]);
            }
        }
        cout << "CMatrix & operator =(CMatrix&& v)" << endl;
        return *this;
    }




    CMatrix& CMatrix::operator=(const CMatrix& V) {

        if (this == &V) {
            return *this;
        }

        rows = V.rows;
        colls = V.colls;
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[colls];
            for (int j = 0; j < colls; j++)
            {
                matrix[i][j] = V.matrix[i][j] % p;
            }
        }

        cout << "CMatrix & operator =(const CMatrix& V)" << endl;

        return *this;

    }

    void CMatrix::print(string n) {
        if (rows == 0 || colls == 0) {
            cout << "Матрица: " << n << "---";
            cout << "матрицы не существует!" << endl;
        }
        else {



            bool isEmpty = true;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < colls; j++) {
                    if (matrix[i][j] > 0) {
                        isEmpty = false;
                    }



                }
            }


            if (isEmpty == false) {
                cout << endl;
                cout << "Матрица: " << n << endl;
                for (int i = 0; i < rows; i++)
                {
                    int printedElements = 0;
                    cout << "( ";
                    for (int j = 0; j < colls; j++)
                    {
                        printedElements++;
                        cout << matrix[i][j] << " ";
                        if (printedElements == colls) {
                            cout << ")";
                            cout << endl;
                            printedElements = 0;
                        }

                    }
                }
            }
            else {
                cout << "Матрица: " << n << "---";
                cout << "в матрице нет элементов!" << endl;
            }
        }
    }
    void CMatrix::ymench() {
        if (rows > 0 && colls > 0) { // Проверка на существование матрицы
            rows--;
            colls--;
            delete[] matrix[rows];
            for (int i = 0; i < rows; i++) {
                int* newtemp = new int[colls];
                for (int j = 0; j < colls; j++) {
                    newtemp[j] = matrix[i][j];
                }
                delete[] matrix[i];
                matrix[i] = newtemp;
            }
        }
    }
    void CMatrix::up() {
        if (rows > 0 && colls > 0) {
            int** temp = new int* [rows + 1];
            for (int i = 0; i < rows + 1; i++)
            {
                temp[i] = new int[colls + 1];
                for (int j = 0; j < colls + 1; j++)
                {
                    if (i == rows || j == colls) {
                        temp[i][j] = 0;
                    }
                    else {
                        temp[i][j] = matrix[i][j];
                    }
                }
            }
            Del();
            matrix = temp;
            rows++;
            colls++;
        }
    }


    CMatrix::~CMatrix() {
        cout << endl;
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << "destructor!:" << "rows= " << rows << " colls= " << colls << endl;
    }
