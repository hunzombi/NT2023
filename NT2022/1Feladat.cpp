#include <iostream>

using namespace std;

int N, M, sz[1000001];
int x, y, cnt;

int main()
{
    cin >> N >> M;
    for (int i=0; i < M; i++){
        cin >> x >> y;
        sz[x]++;
        sz[y]--;
    }
    sz[0] = 1;
    for (int i=2; i <= N; i++){
        if (sz[i] > 0 && sz[i-1] == 0){
            cnt++;
        }
    }
    if (sz[N] == 0){
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
