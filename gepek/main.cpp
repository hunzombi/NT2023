#include <bits/stdc++.h>

using namespace std;

int N, M;

struct pas{
    int x;
    int y;
    int z;
}a[100001];

bool sorted(pas a, pas b){
    return (a.x <= b.x);
}

int main()
{
    cin >> N >> M;
    for (int i=0; i < M; i++){
        cin >> a[i].x;
        a[i].y = 0;
        a[i].z = 0;
    }
    sort(a, a+M, sorted);
    for (int i=0; i < M; i++){
        cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
    }
    return 0;
}
