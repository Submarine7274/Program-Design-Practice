#include<iostream>
#include<vector>
using namespace std;
using Matrix = vector<vector<double>>;
Matrix martixMultiplication(Matrix &a, Matrix &b) {
    int m = a.size();
    int n = a[0].size();
    int p = b[0].size();
    Matrix c(m, vector<double>(p, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
int main() {
    int m, n, p;
    cout << "Enter dimensions (m n p): ";
    cin >> m >> n >> p;
    Matrix a(m, vector<double>(n));
    Matrix b(n, vector<double>(p));
    cout<<"Enter matrix A (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout<<"Enter matrix B (" << n << "x" << p << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> b[i][j];
        }
    }
    cout << "Resultant Matrix C (" << m << "x" << p << "):" << endl;
    Matrix c = martixMultiplication(a, b);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}