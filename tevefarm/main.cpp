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
    if (T[head] >= sum){
        res.push_back(head);
        return T[head];
    }
    return sum;
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
    // Get the max and the cities
    cout << bfs(1) << '\n';
    cout << res.size() << '\n';
    for (int i=0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}
