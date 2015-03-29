#include<iostream>
#include<cmath>
using namespace std;
#define range 2000
/**
*��ɸ���������Ļ���˼���ǣ�
*�Ѵ�1��ʼ�ġ�ĳһ��Χ�ڵ���������С����˳�����У�
*1�������������Ȱ���ɸ����ʣ�µ�����ѡ����С������������Ȼ��ȥ�����ı�����
*�������ƣ�ֱ��ɸ��Ϊ��ʱ������
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
