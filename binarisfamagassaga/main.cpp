#include <iostream>

using namespace std;

int N, M;
int m, x, h, c;
int mag[65537], prevv[65537], prevm[65537];
int el[65537]; // Elozo: 0=bal, 1=jobb, 2=mindketto

int main()
{
    cin >> N >> M;
    m = (1<<N)-1;
    m = m/2;
    for(int i=(1<<N)-1; i > 0; i--){
        if (i == m){
            c++;
            m /= 2;
        }
        mag[i] = 1;
        previ[i] = 2;
        prevm[i] = 1;
        prevv[i] = c;
    }
    for (int i=0; i < M; i++){
        cin >> x >> h;
        mag[x] = h;
        if (h == prevm[x/2]){
            if (el[x/2] == 1 && x % 2 == 0){
                el[x/2] = 2;
            }
        }
        if (h < prevm[x/2]){
            if (el[x/2] == 0 && x % 2 == 0){
                prevm[x/2] = mag[x+1] + prevv[x+1];
            } else if (el[x/2] == 1 && x % 2 == 1){
                prevm[x/2] = mag[x-1] - prevv[x-1];
            }
        }
        if (h > prevm[x/2]){
            prevm[x/2] = h;
            if (x % 2 == 0){
                el[x/2] = 0;
            } else {
                el[x/2] = 1;
            }
            while (x > 0){
                if (prevv[x/2] < prevv[x] + mag[x]){
                    prevv[x/2] = prevv[x] + mag[x];
                    x /= 2;
                } else {
                    break;
                }
            }
        }
        cout << prevv[1] << '\n';
    }
    return 0;
}
