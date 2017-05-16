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

void addition(){
    Matrix a, b;
    cout << "WprowadŸ pierwsza macierz: " << endl;
    cin >> a;
    cout << "WprowadŸ druga macierz: " << endl;
    cin >> b;
    if(a.m == b.m && a.n == b.n){
        a = a + b;
        cout << "Wynik: " << endl << a << endl;
    } else {
         cout << endl << "Nie mozna wykonac dodawania - macierze sa roznych rozmiarow" << endl << endl;
    }
}

void subtraction(){
    Matrix a, b;
    cout << "WprowadŸ pierwsza macierz: " << endl;
    cin >> a;
    cout << "WprowadŸ druga macierz: " << endl;
    cin >> b;
    if(a.m == b.m && a.n == b.n){
        a = a - b;
        cout << "Wynik: " << endl << a << endl;
    } else {
        cout << endl << "Nie mozna wykonac odejmowania - macierze sa roznych rozmiarow" << endl << endl;
    }
}

void multiplcation(){
    Matrix a, b;
    cout << "WprowadŸ pierwsza macierz: " << endl;
    cin >> a;
    cout << "WprowadŸ druga macierz: " << endl;
    cin >> b;
    if(a.m == b.n){
        a = a * b;
        cout << "Wynik: " << endl << a << endl;
    } else {
        cout << endl << "Nie mozna wykonac mnozenia - macierze o nie zgodnych rozmiarach" << endl << endl;
    }
}

void determination(){
    Matrix m;
    cout << "WprowadŸ macierz: " << endl;
    cin >> m;
    if((m.m == 3) && (m.n == 3) || (m.m == 2) && (m.n == 2) || (m.m == 1) && (m.n == 1)) {
        cout << "Wyznacznik wynosi: " << m.determinant() << endl;
    } else {
        cout << "Nie mozna obliczyc - zly rozmiar" << endl;
    }
}

void inversion(){
    Matrix m;
    cout << "WprowadŸ macierz: " << endl;
    cin >> m;
    if(m.m != m.n){
        cout << "Nie mozna obliczyc - macierz nie jest kwadratowa" << endl;
    } else if(m.m > 3) {
        cout << "Nie mozna obliczyc - zbyt wysoki stopien (max 3)" << endl;
    } else {
        m = m.getInversion();
        cout << "Wynik: " << endl << m << endl;
    }
}

void equation(){
    Matrix a, b, c;
    cout << "WprowadŸ macierz A: " << endl;
    cin >> a;
    cout << "WprowadŸ macierz B: " << endl;
    cin >> b;
    cout << "WprowadŸ macierz C: " << endl;
    cin >> c;
    Matrix x(a.m, a.n);
    if((c.m + b.m == c.n + b.n) && (a.m == a.n) && (a.m == c.m) && (a.m < 4)) {
        x = c - b;
        a = a.getInversion();
        x = a - x;
        cout << "Wynik: " << endl << x << endl;
    } else {
        cout << "Nie mozna obliczyc - zle rozmiary" << endl;
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
        cout << "#   2.Rozncia macierzy     #\n";
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
