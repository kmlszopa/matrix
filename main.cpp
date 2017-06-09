#include <iostream>
#include <math.h>
#include <Matrix.h>
#include <stdlib.h>

using namespace std;
void addition();
void subtraction();
void multiplcation();
void equation();
void determination();
void inversion();
void menu();

void setMatrixesSize(Matrix & a, Matrix & b) {
    cout << "Podaj wymiary pierwszej macierzy: " << endl;
    cin >> a;
    cout << "Podaj wymiary drugiej macierzy: " << endl;
    cin >> b;
}

void setMatrixSize(Matrix & a) {
    cout << "Podaj wymiary macierzy: " << endl;
    cin >> a;
}

void preperMatrixes(Matrix & a, Matrix & b) {
    cout << "Wprowadz wspolczynniki pierwszej macierzy: " << endl;
    a.setCoefficients();
    cout << "Wprowadz wspolczynniki drugiej macierzy: " << endl;
    b.setCoefficients();
}


void addition() {
    Matrix a, b;
    setMatrixesSize(a, b);
    if(a.haveMatrixSameSize(b)) {
        preperMatrixes(a, b);
        a = a + b;
        cout << "Wynik: " << endl << a << endl;
    } else {
        cout << endl << "Nie mozna wykonac dodawania - macierze sa roznych rozmiarow" << endl << endl;
    }
}

void subtraction() {
    Matrix a, b;
    setMatrixesSize(a, b);
    if(a.haveMatrixSameSize(b)) {
        preperMatrixes(a, b);
        a = a - b;
        cout << "Wynik: " << endl << a << endl;
    } else {
        cout << endl << "Nie mozna wykonac odejmowania - macierze sa roznych rozmiarow" << endl << endl;
    }
}

void multiplcation() {
    Matrix a, b;
    setMatrixesSize(a, b);
    if(a.n == b.m) {
        preperMatrixes(a, b);
        a = a * b;
        cout << "Wynik: " << endl << a << endl;
    } else {
        cout << endl << "Nie mozna wykonac mnozenia - macierze o nie zgodnych rozmiarach" << endl << endl;
    }
}

void determination() {
    Matrix m;
    setMatrixSize(m);
    cout << "Wprowadz wspolczynniki macierzy: " << endl;
    m.setCoefficients();
    if(m.m == m.n) {
        cout << "Wyznacznik wynosi: " << m.gaussDeterminant() << endl;
    } else {
        cout << "Nie mozna obliczyc - zly rozmiar" << endl;
    }
}

void inversion() {
    Matrix m;
    setMatrixSize(m);
    cout << "Wprowadz wspolczynniki macierzy: " << endl;
    m.setCoefficients();
    if(m.m != m.n) {
        cout << "Nie mozna obliczyc - macierz nie jest kwadratowa" << endl;
    } else if(m.m > 3) {
        cout << "Nie mozna obliczyc - zbyt wysoki stopien (max 3)" << endl;
    } else if(m.gaussDeterminant() == 0) {
        cout << "Nie mozna obliczyc - zerowy wyznacznik" << endl;
    } else {
        m = m.getInversion();
        cout << "Wynik: " << endl << m << endl;
    }
}

void equation() {
    Matrix a, b, c;
    cout << "Wprowadz wymiary macierz A: " << endl;
    setMatrixSize(a);
    cout << "Wprowadz wymiary macierz B: " << endl;
    setMatrixSize(b);
    cout << "Wprowadz wymiary macierz C: " << endl;
    setMatrixSize(c);
    if(c.m != b.m || c.n != b.m || a.m != c.m || a.n != c.n) {
        cout << "Nie mozna obliczyc - zle rozmiary" << endl;
    } else if (a.m > 3) {
        cout << "Nie mozna obliczyc - zle rozmiary" << endl;
    } else {
        cout << "Wprowadz wspolczynniki macierzy A: " << endl;
        a.setCoefficients();
        cout << "Wprowadz wspolczynniki macierzy B: " << endl;
        b.setCoefficients();
        cout << "Wprowadz wspolczynniki macierzy C: " << endl;
        c.setCoefficients();
        if (a.gaussDeterminant() == 0) {
            cout << "Nie mozna obliczyc - zerowy wyznacznik" << endl;
        } else {
            Matrix x(a.m, a.n);
            x = c - b;
            a = a.getInversion();
            x = a - x;
            cout << "Wynik: " << endl << x << endl;
        }
    }
}

void menu() {
    char a;

    do {
        cout << "############################\n";
        cout << "#      MACIERZE  ver.2     #\n";
        cout << "############################\n";
        cout << "#   Co chcesz zrobic?      #\n";
        cout << "#   1.Suma macierzy        #\n";
        cout << "#   2.Roznica macierzy     #\n";
        cout << "#   3.Iloczyn macierzy     #\n";
        cout << "#   4.Oblicz wyznacznik    #\n";
        cout << "#   5.Macierz odwrotna     #\n";
        cout << "#   6.Rownanie AX + B = C  #\n";
        cout << "#   x aby zakonczyc        #\n";
        cout << "############################\n";
        cin >> a;
        system("cls");
        switch (a) {
        case 49:
            addition();
            break;
        case 50:
            subtraction();
            break;
        case 51:
            multiplcation();
            break;
        case 52:
            determination();
            break;
        case 53:
            inversion();
            break;
        case 54:
            equation();
            break;
        default:
            break;
        }
    } while(a!='x');


}

int main() {

    menu();

    return 0;
}
