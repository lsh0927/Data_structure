//문제 1번

#include <iostream>
#include <cmath>
#include <sstream> // stringstream 헤더 추가
using namespace std;

const int MAX_DEGREE = 10;
struct Term {
    int coef;
    int exp;
};
class Polynomial {
private:
    Term terms[MAX_DEGREE];
    int num_terms;
public:
    Polynomial(): num_terms(0) {}
    void print() {
    for (int i = 0; i < num_terms; i++) {
        if (terms[i].exp > 1) {
            if (terms[i].coef == 1) {
                cout << "x^" << terms[i].exp << " ";
            } else {
                cout << terms[i].coef << "x^" << terms[i].exp << " ";
            }
        } else if (terms[i].exp == 1) {
            if (terms[i].coef == 1) {
                cout << "x ";
            } else {
                cout << terms[i].coef << "x ";
            }
        } else if (terms[i].exp == 0) {
            cout << terms[i].coef << " ";
        }
        if (i < num_terms - 1) {
            cout << "+ ";
        }
    }
    cout << endl;
}
    Polynomial operator*(Polynomial& p) {
        Polynomial result;
        for (int i = 0; i < num_terms; i++) {
            for (int j = 0; j < p.num_terms; j++) {
                int new_coef = terms[i].coef * p.terms[j].coef;
                int new_exp = terms[i].exp + p.terms[j].exp;
                bool term_added = false; // 새로운 항이 추가되었는지 확인하는 플래그
                for (int k = 0; k < result.num_terms; k++) {
                    if (result.terms[k].exp == new_exp) {
                        result.terms[k].coef += new_coef; // 이미 존재하는 항의 계수에 더해준다
                        term_added = true;
                        break;
                    }
            }
            if (!term_added) {
                result.add_term(new_coef, new_exp);
            }
        }
    }
        return result;
    }

    void add_term(int coef, int exp) {
        if (num_terms >= MAX_DEGREE) {
            cout << "Too many terms in polynomial" << endl;
            exit(1);
        }
        terms[num_terms].coef = coef;
        terms[num_terms].exp = exp;
        num_terms++;
    }

    int eval(int x) {
        int result = 0;
        for (int i = 0; i < num_terms; i++) {
            result += terms[i].coef * pow(x, terms[i].exp);
        }
        return result;
    }
};
int main() {
    Polynomial A, B, C;
    int coef, exp;

    // input polynomial A
    cout << "Input polynomial A: ";
    string input_str;
    getline(cin, input_str);
    stringstream ss(input_str);
    while (ss >> coef >> exp) {
        A.add_term(coef, exp);
    }
    cout << "A : ";
    A.print();

    // input polynomial B
    cout << "Input polynomial B: ";
    getline(cin, input_str);
    ss.clear();
    ss.str(input_str);
    while (ss >> coef >> exp) {
        B.add_term(coef, exp);
    }
    cout << "B : ";
    B.print();

    C = A * B;
    cout << "C : ";
    C.print();

    cout << "x의 값을 입력하세요: ";
    int x;
    cin >> x;
    int result_a = A.eval(x);
    int result_b = B.eval(x);
    int result_c = C.eval(x);
    
    cout << "C(" << x << ") = " << result_c << endl;

    if (result_c < 50) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }

    return 0;
}




//과제 2번
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSparse(int R, int C, const vector<vector<int> >& A) {
    int cnt = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (A[r][c] != 0) cnt++;
        }
    }
    return (cnt <= (R * C) / 2);
}

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int> > A(R, vector<int>(C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
        }
    }

    if (isSparse(R, C, A)) { // 희소행렬 방식으로 저장
        cout << 2 << '\n';

        // A 배열을 희소행렬로 변환
        vector<pair<int, pair<int, int> > > sparse;
        for (int c = 0; c < C; ++c){
            for (int r = 0; r < R; ++r) {
                if (A[r][c] != 0) {
                    sparse.push_back(make_pair(r+1, make_pair(c+1, A[r][c])));
                }
            }
        }

        // 행 기준으로 정렬
        sort(sparse.begin(), sparse.end());

        // 행이 같을 경우에는 열을 기준으로 오름차순 정렬
        for (int i = 0; i < sparse.size(); ++i) {
            for (int j = i + 1; j < sparse.size(); ++j) {
                if (sparse[i].first == sparse[j].first) { // 행이 같은 경우
                    if (sparse[i].second.first > sparse[j].second.first) { // 열이 더 작은 경우
                        swap(sparse[i], sparse[j]);
                    }
                }
            }
        }

        // 전치행렬 출력
        int prev_row = -1, count = 0;
        for (int c = 1; c <= C; ++c) {
            for (int i = 0; i < sparse.size(); ++i) {
                if (sparse[i].second.first == c) {
                    if (prev_row == -1 || prev_row != sparse[i].first) { // 새로운 섬 묶음의 시작
                        count++;
                        prev_row = sparse[i].first;
                        cout << count << ' ' << sparse[i].first << ' ' << sparse[i].second.second << ' ';
                    } else { // 기존의 섬 묶음에 속하는 경우
                        cout << sparse[i].second.second << ' ';
                    }
                }
            }
            prev_row = -1;
            cout << '\n';
        }
    } else { // A[n][m] 방식으로 저장
        cout << 1 << '\n';

        // 전치행렬 출력
        for (int c = 1; c <= C; ++c) {
            for (int r = 1; r <= R; ++r) {
                cout << A[r-1][c-1] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
