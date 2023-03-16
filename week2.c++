#include <iostream>

using namespace std;

void sort(int *a, const int n);
int BinarySearch(int *a, const int x, const int n);

int main()
{
    const int N = 10;

    //n개의 데이터를 가지는 배열 a를 선언하고, 임의의 데이터 n개로 초기화
    int a[N] = {1,2,3,4,5,6,7,8,9,10};
    //탐색할 데이터 입력, 탐색 결과를 반환하는 변수 선언
    int data, res;

    //탐색할 데이터 입력받아서 data 변수에 저장
    cout << "탐색할 데이터를 입력 : ";
    cin>>data;
    
    
    //정의한 배열과 데이터 갯수를 인자로 하여 정렬 함수 호출
    sort(a,N);                  

    //정렬을 마친 배열과 탐색하고자 하는 데이터(값), 그리고 데이터 갯수를 인자로 하여 탐색 함수 호출
    //반환값은 선언한 결과 변수에 저장
    res=BinarySearch(a, data, N);
    //정렬된 배열을 띄어쓰기 하면서 출력
    for(int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;

    //조건문을 통해서 출력을 조절
    //데이터를 찾지 못하면 -1이 반환되기 때문에, 결과값이 0보다 작으면 데이터 탐색 실패에 대한 메시지 출력
    if(res >= 0)
        cout << "데이터 " << data << "의 위치는 index " << res << "입니다." << endl;
    else
        cout << "데이터 " << data << "는 배열에 존재하지 않습니다." << endl;
}

void sort(int *a, const int n)
{
    //메인함수에서 정의한 배열을 참조 호출로 가져옴
    //n개의 데이터로 이루어진 배열 a에 대해서 선택정렬 알고리즘 수행
    //강의자료 슬라이드 8 참조
    for(int i=0;i<n;i++)
    {
        int j=i;
        for(int k=i+1;k<n;k++)
        {
            if(a[k]<a[j]) j=k;
        }
        swap(a[i],a[j]);
    }
}

int BinarySearch(int *a, const int x, const int n)
{
	//메인함수에서 정의하고, sort 함수를 통해서 정렬한 배열을 참조 호출로 가져옴
    //n개의 데이터로 이루어진 배열 a에 대해서, 데이터 x를 찾는 이원탐색 알고리즘 수행
    //강의자료 슬라이드 22 참조
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(x<a[middle])
            right=middle-1;
        else if(x>a[middle])
            left=middle+1;
        else
            return middle;

    }
    return -1;
}
