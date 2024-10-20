#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int MinInRow(int** a, const int row, const int colCount);
int sum(int** a, int k, int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 5;
    int High = 51;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    cout << "sum= " << sum( a, k, n) << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int MinInRow(int** a, const int row, const int colCount)
{
    int min = a[row][0];
    for (int j = 1; j < colCount; j++)
    {
        if (a[row][j] < min)
        {
            min = a[row][j];
        }
    }
    return min;
}

int sum(int** a, int k, int n)
{
    int sum = 0;
    for (int i = 0;i < k;i++)
    {
        sum += MinInRow(a, i, n);
    }
    return sum;
}