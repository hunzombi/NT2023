#include <iostream>

using namespace std;

int N, P, l, r, m;
int arr[100001];
int sum;

int main()
{
    cin >> N >> P;
    m = N;
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
    sum = arr[0];
    while (r < N){
        if (sum < P){
            r++;
            sum += arr[r];
        } else {
            sum -= arr[l];
            if (r-l+1 < m){
                m = r-l+1;
            }
            l++;
        }
        if (l > r){
            l = r;
        }
    }
    cout << m << '\n';
    return 0;
}
