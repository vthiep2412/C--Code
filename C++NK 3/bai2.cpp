#include <bits/stdc++.h>
using namespace std;

bool tg(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {return true;}
    return false;
}
bool deu(int a, int b, int c) {
    if (a == b && b == c) {return true;}
    return false;
}
bool vuong(int a, int b, int c) {
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {return true;}
    return false;
}
bool can(int a, int b, int c) {
    if (a == b || a == c || b == c) {return true;}
    return false;
}
bool vuongcan(int a, int b, int c) {
    if (vuong(a, b, c) && can(a, b, c)) {return true;}
    return false;
}
bool nhon(int a, int b, int c) {
    if (a*a + b*b > c*c && a*a + c*c > b*b && b*b + c*c > a*a) {return true;}
    return false;
}
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if (tg(a, b, c))
        {
            if (deu(a, b, c)) cout << "đều";
            else if (vuongcan(a, b, c)) cout << "vuông cân";
            else if (vuong(a, b, c)) cout << "vuông";
            else if (can(a, b, c)) cout << "cân";
            else if (nhon(a, b, c)) cout << "nhọn";
            else cout << "tù";
        }
    else cout << "không tạo thành tam giác";
    return 0;
}