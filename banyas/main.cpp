#include <bits/stdc++.h>
using namespace std;

int N;
long long s, l, r, xp, t, kov;
pair<long long, long long>arr[100000];

bool comp(pair<int, int>a, pair<int, int> b){
    return (a.first < b.first);
}

int main()
{
    cin >> N;
    for (int i=0; i < N; i++){
        cin >> arr[i].first;
    }
    for (int i=0; i < N; i++){
        cin >> arr[i].second;
        s += arr[i].second;
    }
    sort(arr, arr+N, comp);
    r = N-1;
    while (s > 0){
        if (arr[l].first <= xp){
            t += arr[l].second;
            xp += arr[l].second;
            s -= arr[l].second;
            arr[l].second = 0;
            l++;
        }
        if (arr[l].first > xp){
            kov = arr[l].first - xp;
            xp += min(arr[r].second, kov);
            s -= min(arr[r].second, kov);
            t += 2*min(arr[r].second, kov);
            arr[r].second -= min(arr[r].second, kov);
            if (arr[r].second == 0){
                r--;
            }
        }
    }
    cout << t << '\n';

    return 0;
}
