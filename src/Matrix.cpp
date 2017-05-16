#include "Matrix.h"
#include "iostream"

using namespace std;

Matrix::Matrix(){}

Matrix::~Matrix(){}

Matrix::Matrix(int m, int n){
    this->m = m;
    this->n = n;
    elements = new double * [m];
    for (int i = 0; i < m; i++) elements[i] = new double [n];
    int i,j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            elements[i][j] = 0;
        }
    }
}

istream & operator >> (istream & s, Matrix & matrix){
    cout << "Podaj ilosc wierszy:\n";
    s >> matrix.m;
    cout << "Podaj ilosc kolumn:\n";
    s >> matrix.n;
    matrix.elements = new double * [matrix.m];
    for (int i = 0; i < matrix.m; i++) matrix.elements[i] = new double [matrix.n];
    int i,j;
    for(i = 0; i < matrix.m; i++) {
        for(j = 0; j < matrix.n; j++) {
            cout << "Podaj wspolczynniki macierzy o wspolrzednych [" << i << "][" << j << "]" << endl;
            s >> matrix.elements[i][j];
        }
    }
    return s;
}

ostream & operator << (ostream & s, Matrix & matrix ){
    for(int i=0; i<matrix.m; i++) {
        for(int j=0; j<matrix.n; j++) {
            s.precision(2);
            s.width(7);
            s << matrix.elements[i][j];

        }
        s << endl;
    }
    return s;
}

Matrix Matrix::operator - (const Matrix & matrix) {
    if(matrix.m == m && matrix.n == n) {
        Matrix o = matrix;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                o.elements[i][j] = elements[i][j] - matrix.elements[i][j];
            }
        }
        return o;
    }
}

Matrix Matrix::operator + (const Matrix & matrix) {
    if(matrix.m == m && matrix.n == n) {
        Matrix o = matrix;
        for(int i=0; i < m; i++)
        {
            for(int j=0; j < n; j++)
            {
                o.elements[i][j] = elements[i][j] + matrix.elements[i][j];
            }
        }
        return o;
    }
}

Matrix Matrix::operator * (const Matrix & matrix){
    if(n == matrix.m){
        Matrix o(m, n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < matrix.n; j++) {
                for(int k = 0; k < n; k++) {
                    o.elements[i][j] = o.elements[i][j] + (elements[i][k] * matrix.elements[k][j]);
                }
            }
        }
    return o;
    }
}

double Matrix::determinant(){
    double result;
    if((m == 3) && (n == 3)) {
        result = (elements[0][0] * elements[1][1] * elements[2][2]) + (elements[0][1] * elements[1][2] * elements[2][0]) + (elements[0][2] * elements[1][0] * elements[2][1])
                -(elements[0][2] * elements[1][1] * elements[2][0]) - (elements[0][0] * elements[1][2] * elements[2][1]) - (elements[0][1] * elements[1][0] * elements[2][2]);
    } else if((m == 2) && (n == 2)) {
        result = (elements[0][0] * elements[1][1]) - (elements[0][1] * elements[1][0]);
    } else if((m == 1) && (n == 1)) {
        result = elements[0][0];
    }
    return result;
}

Matrix Matrix::getInversion(){
    Matrix o(m, n);
    int sign = 1;
    if((m == 3) && (n == 3)) {
        o.elements[0][0] = (1 / determinant()) *  sign * ((elements[1][1] * elements[2][2]) - (elements[1][2] * elements[2][1]));
        o.elements[1][0] = (1 / determinant()) * -sign * ((elements[1][0] * elements[2][2]) - (elements[2][0] * elements[1][2]));
        o.elements[2][0] = (1 / determinant()) *  sign * ((elements[1][0] * elements[2][1]) - (elements[1][1] * elements[2][0]));
        o.elements[0][1] = (1 / determinant()) * -sign * ((elements[0][1] * elements[2][2]) - (elements[0][2] * elements[2][1]));
        o.elements[1][1] = (1 / determinant()) *  sign * ((elements[0][0] * elements[2][2]) - (elements[2][0] * elements[0][2]));
        o.elements[2][1] = (1 / determinant()) * -sign * ((elements[0][0] * elements[2][1]) - (elements[2][0] * elements[0][1]));
        o.elements[0][2] = (1 / determinant()) *  sign * ((elements[0][1] * elements[1][2]) - (elements[1][1] * elements[0][2]));
        o.elements[1][2] = (1 / determinant()) * -sign * ((elements[0][0] * elements[1][2]) - (elements[1][0] * elements[0][2]));
        o.elements[2][2] = (1 / determinant()) *  sign * ((elements[0][0] * elements[1][1]) - (elements[1][0] * elements[0][1]));
    } else if((m == 2) && (n == 2)) {
        o.elements[0][0] = (1 / determinant()) *  sign * elements[1][1];
        o.elements[1][0] = (1 / determinant()) * -sign * elements[1][0];
        o.elements[0][1] = (1 / determinant()) *  sign * elements[0][1];
        o.elements[1][1] = (1 / determinant()) * -sign * elements[0][0];
    } else if((m == 1) && (n == 1)) {
        o.elements[0][0] = 1 / elements[0][0];
    }
    return o;
}
