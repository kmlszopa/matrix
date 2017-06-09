#ifndef MATRIX_H
#define MATRIX_H
#include "iostream"

using namespace std;
class Matrix
{
public:

    double ** elements;
    int m, n;

    Matrix();
    Matrix(int m, int n);
    virtual ~Matrix();

    Matrix operator - (const Matrix & matrix);
    Matrix operator + (const Matrix & matrix);
    Matrix operator * (const Matrix & matrix);
    Matrix getInversion();
    double gaussDeterminant();
    void setCoefficients();
    bool haveMatrixSameSize(Matrix b);

    friend istream & operator >> (istream & s, Matrix & matrix );
    friend ostream & operator << (ostream & s, Matrix & matrix );

};

#endif // MATRIX_H
