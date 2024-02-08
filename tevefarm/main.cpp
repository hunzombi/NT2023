#include <bits/stdc++.h>

using namespace std;

int N;
int T[100001];
int x;
vector<int> R[100001]; // Relations
vector<int> res;
int S[100001];

int bfs(int head){
    int sum=0;
    for (int i=0; i < R[head].size(); i++){
        sum += bfs(R[head][i]);
    }
    S[head] = sum;
    if (T[head] >= sum){
        return T[head];
    }
    return S[head];
}

int fs(int head){
    if (S[head] <= T[head]){
        res.push_back(head);
        return 0;
    }
    for (int i=0; i < R[head].size(); i++){
        fs(R[head][i]);
    }
    return 0;
}

int main()
{
    cin >> N;
    for (int i=1; i <= N; i++){
        cin >> T[i];
    }
    for (int i=2; i <= N; i++){
        cin >> x;
        R[x].push_back(i);
    }
    bfs(1);

    // Search for result

    fs(1);

    // Get the max and the cities
    cout << bfs(1) << '\n';
    cout << res.size() << '\n';
    for (int i=0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}
