#include<iostream>
#include<stdlib.h>
#include<time.h>
#define random(x)(rand()%x)
using namespace std;
//辗转相除法
int Abs(int a, int b) {
    return a-b>=0 ? a-b : b-a;
}

int Min(int a, int b) {
    return a > b ? b : a;
}
int Gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return Gcd(b, a % b);
}
//stein 算法
int GcdOfStein(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a % 2 == 0 && b % 2 == 0) return 2 * GcdOfStein(a>>1,b>>1);
    else if (a % 2 == 0 && b % 2 != 0) return GcdOfStein(a>>1, b>>1);
    else if (a % 2 != 0 && b % 2 == 0) return GcdOfStein(a, b>>1);
    else return GcdOfStein(Abs(a,b),Min(a,b));
}
int main() {
   srand((int)time(0));
   int a,b;
   a = random(100);
   b = random(100);
   cout << a << " and " << b << endl;

   int gcd = Gcd(a,b);
   cout << gcd;
   return 0;
}
