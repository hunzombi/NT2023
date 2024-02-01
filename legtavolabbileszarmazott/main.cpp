#include <bits/stdc++.h>

using namespace std;

int N, a, b, head, res, ri;
int apa[100001];
int t[100001];
vector<int> fiu[100001];

void bfs(int node, int tav){
    t[node] = tav;
    for (int i=0; i < fiu[node].size(); i++){
        bfs(fiu[node][i], tav+1);
    }
}

int main()
{
    cin >> N;
    for (int i=0; i < N-1; i++){
        cin >> a >> b;
        apa[b] = a;
        fiu[a].push_back(b);
    }
    for (int i=1; i <= N && head == 0; i++){
        if (apa[i] == 0){
            head = i;
        }
    }
    bfs(head, 0);
    for (int i=1; i <= N; i++){
        if (t[i] > res){
            res = t[i];
            ri = i;
        }
    }
    cout << ri << '\n';
    return 0;
}
