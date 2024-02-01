#include <iostream>

using namespace std;

int T, A, B, a, b, res, c;
int prime[101];
bool p[101];
int arr[100], brr[100] //100 last index

void szita(){
    p[c] = 2;
    c++;
    for (int i=4; i <= 100; i+=2){
        p[i] = true;
    }
    for (int i=3; i <= 100; i+=2){
        if (!p[i]){
            prime[c] = i;
            c++;
        }
        for (int j=i; j <= 100; j+=i){
            p[i] = true;
        }
    }
}

int main()
{
    cin >> T;
    for (int i=0; i < T; i++){
        cin >> A >> B;
        res = 1;
        a = b = 1;
        A--;
        B--;
    }
    /* A B
       1 2 3 5 7
       1 2 3 5
    */
    return 0;
}
