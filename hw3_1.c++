#include <iostream>

const int SIZE = 10;

using namespace std;

void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE], int p, int q, int n, int m) {
    if (p != n || q != m)
    {
        cout << "계산 오류" << endl;
        exit(1); //예외처리, 시스템 바로 종료
    }
    else {
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }
}

void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE], int p, int q, int n, int m) {
    if (p != n || q != m)
    {
        cout << "계산 오류" << endl;
        exit(1);
    }
    else {
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    }
}

void printMatrix(int a[SIZE][SIZE], int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {
    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];
    int R1, R2;
    int C1, C2;
    //각 행의 원소는 -100~100
    // 행과 열의 수는 10이하
    // a의 행과 b의 열, a의 열과 b의 행은 같아야 함
    cout << "input R1 and C1";
    cout << endl;
    cin >> R1 >> C1;

    
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "input R2 and C2";
    cout << endl;
    cin >> R2 >> C2;

    
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++)
        {
            cin >> b[i][j];
        }
    }
    addMatrix(a, b, c, R1, C1, R2, C2);
    printMatrix(c, R1, C1);

    subMatrix(a, b, c, R1, C1, R2, C2);
    printMatrix(c, R2, C2);


}