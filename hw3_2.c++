#include <iostream>

using namespace std;

void sort(int* a, const int n)
// n개의 정수 a[0]부터 a[n-1]까지 비감소순으로 정렬한다.
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        // a[i]와 a[n-1] 사이에 가장 작은 정수를 찾는다. (1)
        for (int k = i + 1; k < n; k++)
            if (a[k] < a[j]) j = k;
        // 교환 (2)
        swap(a[i], a[j]);
    }
}

int BinarySearch(int* a, const int x, const int n)
{
    int left = 0;
    int right = n - 1;
    int result = n; 
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (x <= a[middle]) {
            result = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    if (result == n) {
        cout << "ERROR "<< endl;
    }
    return result;
}

int main() {
    int N;
    int X;
    cout << "input nums of sequence & standard" << endl;
    cin >> N >> X;

    const int SIZE = 100; // 수열의 수 조정, 문제에 주어진 범위가 없으므로 임시 지정
    int a[SIZE] = { 0 };
    
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a, N);

    int result = BinarySearch(a, X, N); //result는 배열에서 탐색한 index
    if (a[result] != X) //만약 배열에 탐색하고자 하는 원소가 없으면
    {
        if (result != -1) {

            for (int i = result; i < N; i++) { //해당하는 원소(인덱스)는 자동으로 건너뛰어짐
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else { //기준값이 잘못 되었다는 의미이므로
            cout << "ERROR" << endl;
        }
    }
    else { //배열에 탐색하고자 하는 원소가 있으면
        if (result != -1) {  //result(제대로 된 index)가 나왔을 때

            for (int i = result+1; i < N; i++) { //result보다 "큰" 원소를 출력해야 하므로 index+1 
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else { 
            cout << "ERROR" << endl;
        }
    }
  
    return 0;
}
