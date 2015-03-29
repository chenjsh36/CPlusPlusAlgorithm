#include<iostream>
#include<cmath>
using namespace std;
#define range 2000
/**
*用筛法求素数的基本思想是：
*把从1开始的、某一范围内的正整数从小到大顺序排列，
*1不是素数，首先把它筛掉。剩下的数中选择最小的数是素数，然后去掉它的倍数。
*依次类推，直到筛子为空时结束。
*/
void set(bool IsPrime[]) {
    int i, j;
    for (i = 0; i <= range; i++) {
        IsPrime[i] = true;
    }
    IsPrime[0] = IsPrime[1] = false;
    for (i = 2; i <= range; ++i) {
        if (IsPrime[i]) {
            for (j = 2 * i; j <= range; j+= i) {
                IsPrime[j] = false;
            }
        }
    }
    for (i = 0; i <= range; i++) {
        if (IsPrime[i] == true) {
            cout << i << endl;
        }
    }
}
//a more faster way to find Prime under big data

int main() {
    //bool a[range];
    //set(a);
    int N;
    cin >>N;
    int *Location = new int[N+1];
    for (int i = 0; i != N+1; ++i) {
        Location[i] = i;
    }
    Location[1] = 0;

    int p,q,end;
    end = sqrt((double)N) + 1;
    for (p = 2; p != end; ++p) {
        if (Location[p]) {
            for (q = p; q * p <= N; ++q) {
                if (Location[q]) {
                    for (int k = p * q; k <= N; k *= p) {
                        Location[k] = 0;
                    }
                }
            }
        }
    }
    int m = 0;
    for (int i = 0; i != N; ++i) {
        if (Location[i] != 0) {
            cout << Location[i] << " ";
            ++m;
        }
        if (m % 10 == 0) cout << endl;

    }
    cout << endl << m << endl;
    return 0;
}
