#include <bits/stdc++.h>

using namespace std;

int N, M, S, F, x, y, sv, cv; // sv - start vonala, cv - vegmegallo vonala
int sz[10001];
bool ar[200][200];
vector<int> arr[10001];
vector<int>vec[10001];

int main()
{
    cin >> N >> M >> S >> F;
    for (int i=1; i <= N; i++){
        cin >> x;
        for (int j=0; j < x; j++){
            cin >> y;
            vec[y].push_back(i);
        }
    }

    for (int i=1; i <= 10000; i++){
        for (int j=0; j < vec[i].size(); j++){
            if (vec[i][j] != i){
                ar[i][j] = vec[i][j];
            }
        }
    }
    for (int i=1; i <= 200; i++){
        for (int j=1; j <= 200; j++){
            if (ar[i][j]){
                arr[i][j] = j;
                cout << arr[i][j];
            }
        }
    }
    return 0;
}
