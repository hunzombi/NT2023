#include <iostream>

using namespace std;

/*
    Az az otlet hogy lesz 4 pointer
    2 fent 2 lent
*/

int T, A, B, a, b, res, c;
int ai, bi; // next index of arr and brr
int sa, sb; // sum arr, sum brr
int l1, l2, r1, r2;
int prime[101];
bool p[501];
int arr[101], brr[101]; //100 last index

void szita(){
    p[c] = 2;
    c++;
    for (int i=4; i <= 500; i+=2){
        p[i] = true;
    }
    for (int i=3; i <= 500; i+=2){
        if (!p[i]){
            prime[c] = i;
            c++;
        }
        for (int j=i; j <= 500; j+=i){
            p[i] = true;
        }
    }
}

int main()
{
    szita();
    cin >> T;
    for (int i=0; i < T; i++){
        cin >> A >> B;
        res = 1;
        a = b = 1;
        A--;
        B--;

        // Num to arr of prime numers

        while (sa <= A){
            arr[ai] = prime[ai];
            sa += arr[ai];
            ai++;
        }
        while (sb <= B){
            brr[bi] = prime[bi];
            sb += brr[bi];
            bi++;
        }

        r1 = r2 = 1;

        // Calculating number of possible combinations
    }
    /* A B
       1 2 3 5 7
       1 2 3 5
    */
    return 0;
}
