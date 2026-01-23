#include <bits/stdc++.h>
using namespace std;
#define xQ bool
#define Vz const
#define mY int
#define Jp long long
#define aL return
#define wX freopen
#define dF stdin
#define ZY stdout
#define rK sqrt
#define qG if
#define kT for
#define H2 cin
#define L8 cout
#define C7 main
xQ Q9(Jp T5){qG(T5<2)aL false;qG(T5==2||T5==3)aL true;qG(T5%2==0||T5%3==0)aL false;Vz Jp G6=rK(T5);kT(Jp p4=5;p4<=G6;p4+=6){qG(T5%p4==0||T5%(p4+2)==0)aL false;}aL true;}mY C7(){wX("mang03.inp","r",dF);wX("mang03.out","w",ZY);mY F3,Y5=0;H2>>F3;kT(mY X9=1;X9<=F3;X9++){mY P8;H2>>P8;qG(Q9(P8))Y5++;}L8<<Y5;aL 0;}
