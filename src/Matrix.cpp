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
    s >> matrix.m;
    s >> matrix.n;

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

void Matrix::setCoefficients(){
    elements = new double * [m];
    for (int i = 0; i < m; i++) elements[i] = new double [n];
    int i,j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            cin >> elements[i][j];
        }
    }
}

bool Matrix::haveMatrixSameSize(Matrix b){
    if(m == b.m && n == b.n){
        return true;
    } else {
        return false;
    }
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
        Matrix o(m, m);
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
double Matrix::gaussDeterminant(){
    double result;
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = i + 1; k < m; k++){
                elements[j][k] -= elements[j][i] / elements[i][i] * elements[i][k];
            }
        }
    }
    result = 1;
    for(int i = 0; i < m; i++){
        result *= elements[i][i];
    }
    return result;
}



Matrix Matrix::getInversion(){
    Matrix o(m, n);
    int sign = 1;
    if((m == 3) && (n == 3)) {
        o.elements[0][0] = (1 / gaussDeterminant()) *  sign * ((elements[1][1] * elements[2][2]) - (elements[1][2] * elements[2][1]));
        o.elements[1][0] = (1 / gaussDeterminant()) * -sign * ((elements[1][0] * elements[2][2]) - (elements[2][0] * elements[1][2]));
        o.elements[2][0] = (1 / gaussDeterminant()) *  sign * ((elements[1][0] * elements[2][1]) - (elements[1][1] * elements[2][0]));
        o.elements[0][1] = (1 / gaussDeterminant()) * -sign * ((elements[0][1] * elements[2][2]) - (elements[0][2] * elements[2][1]));
        o.elements[1][1] = (1 / gaussDeterminant()) *  sign * ((elements[0][0] * elements[2][2]) - (elements[2][0] * elements[0][2]));
        o.elements[2][1] = (1 / gaussDeterminant()) * -sign * ((elements[0][0] * elements[2][1]) - (elements[2][0] * elements[0][1]));
        o.elements[0][2] = (1 / gaussDeterminant()) *  sign * ((elements[0][1] * elements[1][2]) - (elements[1][1] * elements[0][2]));
        o.elements[1][2] = (1 / gaussDeterminant()) * -sign * ((elements[0][0] * elements[1][2]) - (elements[1][0] * elements[0][2]));
        o.elements[2][2] = (1 / gaussDeterminant()) *  sign * ((elements[0][0] * elements[1][1]) - (elements[1][0] * elements[0][1]));
    } else if((m == 2) && (n == 2)) {
        o.elements[0][0] = (1 / gaussDeterminant()) *  sign * elements[1][1];
        o.elements[1][0] = (1 / gaussDeterminant()) * -sign * elements[1][0];
        o.elements[0][1] = (1 / gaussDeterminant()) *  sign * elements[0][1];
        o.elements[1][1] = (1 / gaussDeterminant()) * -sign * elements[0][0];
    } else if((m == 1) && (n == 1)) {
        o.elements[0][0] = 1 / elements[0][0];
    }
    return o;
}
