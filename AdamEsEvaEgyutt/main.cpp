#include <bits/stdc++.h>

using namespace std;

int p, A, E;
priority_queue<pair<int, int> > AA, EE;
priority_queue<pair<int, int> > res;
priority_queue<pair<int, int> > result; // Reverse Ordered res
int k, v, ma, mi;
int ka, va, ke, ve;

int main()
{
    cin >> p;
    cin >> A;
    for (int i=0; i < A; i++){
        cin >> k >> v;
        AA.push({-k, -v});
    }
    cin >> E;
    for (int i=0; i < E; i++){
        cin >> k >> v;
        EE.push({-k, -v});
    }

    while (!AA.empty() && !EE.empty()){
        ka = -AA.top().first;
        va = -AA.top().second;
        ke = -EE.top().first;
        ve = -EE.top().second;
        if (va <= ke){
            AA.pop();
            continue;
        }
        if (ve <= ka){
            EE.pop();
            continue;
        }
        ma = max(ka, ke);
        mi = min(va, ve);
        if (ma < mi){
            res.push({-ma, -mi});
            if (va < ve){
                AA.pop();
            } else {
                EE.pop();
            }
        }
    }

    // MERGE

    while (!res.empty()){
        int w = result.size();
        k = -res.top().first;
        v = -res.top().second;
        res.pop();
        if (result.size() == 0){
            result.push({k, v});
            continue;
        }
        if (k > result.top().second){
            result.push({k, v});
        } else if (v > result.top().second){
            k = result.top().first;
            result.pop();
            result.push({k, v});
        }
    }

    // RESULT

    for (int i=0; i < result.size(); i++){
        k = result.top().first;
        v = result.top().second;
        result.pop();
        result.push({-k, -v});
    }

    cout << result.size() << '\n';
    while (!result.empty()){
        cout << -result.top().first << ' ' << -result.top().second << '\n';
        result.pop();
    }

    return 0;
}
