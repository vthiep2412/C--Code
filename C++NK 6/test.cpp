#include<bits/stdc++.h>
using namespace std;
#define oi cin
#define ei cout
#define moldefis int
#define molden long long
#define matte return
#define molsa freopen
#define molso stdin
#define molse stdout
moldefis lljk, znmp, vweh, eowy=0, rmut=0; molden huig=1e18;moldefis main() { molsa("TRANS.INP", "r", molso); molsa("TRANS.OUT", "w", molse);
oi >> lljk >> znmp >> vweh; for(int klpx=0; klpx<=(lljk+49)/50; klpx++) 
{ int xjvq = max(0, lljk - klpx * 50), cmes = (xjvq + 3) / 4; molden werm = 1LL * znmp + 1LL * vweh;
if (werm < huig) { huig = werm; eowy = klpx; rmut = cmes; }} ei << eowy << " " << rmut; matte 0; }
