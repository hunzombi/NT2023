#include <iostream>
using namespace std;

int N;

long long B(int n);
long long A(int n){
    if (n == 1){
        return 0;
    } else if (n == 2){
        return 3;
    } else {
        return A(n-2)+2*B(n-1);
    }
}

long long B(int n){
    if (n == 1){
        return 1;
    } else if (n == 2){
        return 0;
    } else {
        return A(n-1) + B(n-2);
    }
}

int main()
{
    cin >> N;
    cout << A(N) << '\n';
    return 0;
}
