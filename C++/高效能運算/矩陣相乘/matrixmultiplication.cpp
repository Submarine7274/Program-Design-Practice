#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;    
using namespace chrono;
using Matrix = vector<vector<double>>;
using Vector = vector<double>;

Matrix loopijk(Matrix &a, Matrix &b);   //基本矩陣乘法
Matrix loopikj(Matrix &a, Matrix &b);   //loop reordering
Matrix matrixColumnMultiply(const Matrix &A, const Matrix &B);  //Matrix–Column
Matrix matrixMultiplyBlockedNoCopy(const Matrix &A, const Matrix &B, int blockSize);    //Block 無 copy
Matrix matrixMultiplyBlockedWithCopy(const Matrix &A, const Matrix &B, int blockSize);  //Block with copy

//基本矩陣乘法
Matrix loopijk(Matrix &a, Matrix &b) {
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
//loop reordering
Matrix loopikj(Matrix &a, Matrix &b) {
    int m = a.size();
    int n = a[0].size();
    int p = b[0].size();
    Matrix c(m, vector<double>(p, 0));
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < p; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

//Matrix–Column
Vector matrixVectorMultiply(const Matrix &A, const Vector &v) {
    int m = A.size();
    int n = A[0].size();
    Vector result(m, 0.0);
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            result[i] += A[i][k] * v[k];
        }
    }
    return result;
}

Matrix matrixColumnMultiply(const Matrix &A, const Matrix &B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();
    Matrix C(m, vector<double>(p, 0.0));

    for (int j = 0; j < p; ++j) {
        Vector columnB(n);
        for (int i = 0; i < n; ++i) {
            columnB[i] = B[i][j];
        }
        Vector columnC = matrixVectorMultiply(A, columnB);
        for (int i = 0; i < m; ++i) {
            C[i][j] = columnC[i];
        }
    }
    return C;
}

//Block 無 copy
void blockMultiplyColumn(const Matrix &A, const Matrix &B, Matrix &C,
                         int iStart, int iEnd, int jStart, int jEnd, int kStart, int kEnd)
{
    for (int j = jStart; j < jEnd; ++j) {
        for (int i = iStart; i < iEnd; ++i) {
            double sum = 0.0;
            for (int k = kStart; k < kEnd; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
        }
    }
}

Matrix matrixMultiplyBlockedNoCopy(const Matrix &A, const Matrix &B, int blockSize) {
    int n = A.size();
    Matrix C(n, vector<double>(n, 0.0));

    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                int iEnd = min(ii + blockSize, n);
                int jEnd = min(jj + blockSize, n);
                int kEnd = min(kk + blockSize, n);

                blockMultiplyColumn(A, B, C, ii, iEnd, jj, jEnd, kk, kEnd);
            }
        }
    }
    return C;
}

//Block with copy
Matrix matrixMultiplyBlockedWithCopy(const Matrix &A, const Matrix &B, int blockSize) {
    int n = A.size();
    Matrix C(n, vector<double>(n, 0.0));
    Matrix Ab(blockSize, vector<double>(blockSize, 0.0));
    Matrix Bb(blockSize, vector<double>(blockSize, 0.0));

    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                int iEnd = min(ii + blockSize, n);
                int jEnd = min(jj + blockSize, n);
                int kEnd = min(kk + blockSize, n);

                // copy A block
                for (int i = ii; i < iEnd; ++i)
                    for (int k = kk; k < kEnd; ++k)
                        Ab[i - ii][k - kk] = A[i][k];

                // copy B block
                for (int k = kk; k < kEnd; ++k)
                    for (int j = jj; j < jEnd; ++j)
                        Bb[k - kk][j - jj] = B[k][j];

                // multiply the copied blocks
                for (int i = 0; i < iEnd - ii; ++i)
                    for (int j = 0; j < jEnd - jj; ++j)
                        for (int k = 0; k < kEnd - kk; ++k)
                            C[ii + i][jj + j] += Ab[i][k] * Bb[k][j];
            }
        }
    }
    return C;
}
int main() {
    int n;
    cout << "Enter dimensions (n X n): ";
    cin >> n;
    Matrix a(n, vector<double>(n,1.1));
    Matrix b(n, vector<double>(n,1.1));
    vector<int> blockSizes = {16, 32, 64, 128, 256};
    double bestTime = 1e9;
    int bestBlock = 0;

    cout << fixed << setprecision(6);
    for (int i : blockSizes) {
        auto start = high_resolution_clock::now();
        Matrix C = matrixMultiplyBlockedWithCopy(a, b, i);
        auto end = high_resolution_clock::now();
        double seconds = duration_cast<nanoseconds>(end - start).count() * 1e-9;
        cout << "Block size " << i << " => Time: " << seconds << " seconds" << endl;
        if (seconds < bestTime) {
            bestTime = seconds;
            bestBlock = i;
        }
    }

    auto start = high_resolution_clock::now();
    Matrix c = loopijk(a, b);
    auto end = high_resolution_clock::now();
    auto loopijkDuration = duration_cast<nanoseconds>(end - start);

    start = high_resolution_clock::now();
    c = loopikj(a, b);
    end = high_resolution_clock::now();
    auto loopikjDuration = duration_cast<nanoseconds>(end - start);

    start = high_resolution_clock::now();
    c = matrixColumnMultiply(a, b);
    end = high_resolution_clock::now();
    auto matrixColumnDuration = duration_cast<nanoseconds>(end - start);

    start = high_resolution_clock::now();
    c = matrixMultiplyBlockedNoCopy(a, b, bestBlock);
    end = high_resolution_clock::now();
    auto blockedNoCopyDuration = duration_cast<nanoseconds>(end - start);

    start = high_resolution_clock::now();
    c = matrixMultiplyBlockedWithCopy(a, b, bestBlock);
    end = high_resolution_clock::now();
    auto blockedWithCopyDuration = duration_cast<nanoseconds>(end - start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << fixed << setprecision(9);
    cout << endl;
    cout << "Matrix C using loopijk:" << endl;
    cout << "Time taken: " << loopijkDuration.count()* 1e-9 << " seconds" << endl;
    cout << "Matrix C using loopikj:" << endl;
    cout << "Time taken: " << loopikjDuration.count()* 1e-9 << " seconds" << endl;
    cout << "Matrix C using Matrix-Column:" << endl;
    cout << "Time taken: " << matrixColumnDuration.count()* 1e-9 << " seconds" << endl;
    cout<<"Best block size so far: " << bestBlock << " with time " << bestTime << " seconds" << endl;
    cout << "Matrix C using Blocked (No Copy):" << endl;
    cout << "Time taken: " << blockedNoCopyDuration.count()* 1e-9 << " seconds" << endl;
    cout << "Matrix C using Blocked (With Copy):" << endl;
    cout << "Time taken: " << blockedWithCopyDuration.count()* 1e-9 << " seconds" << endl;
    return 0;
}