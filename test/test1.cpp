#include <bits/stdc++.h>
using namespace std;
// cái này cx phải có


// hàm này cx cần phải có, ko co la ko chay dc
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //  hai dong nay la de tang toc
    //freopen("TEST1.INP", "r", stdin); khi di thi , phai co
    //dong nhap
    //freopen("TEST1.OUT", "w", stdout);  khi di thi , phai co
    // dong xuat

    // oke giờ đến cái chính phải học
    // 1 data type
    // oke data type thi m phai dung can than
    // bao gom, int, long long, vector, char, string, double, long double, bool
    // để khai báo thì viết:
    int a; // int là số nguyên, a là tên biến
    long long b; // long long là số nguyên lớn hơn int
    vector<int> c; // vector là mảng động, khác vs mảng thường nó thông minh hơn(khuyên dùng)  
    char d; // char là kí tự
    string e; // string là chuỗi kí tự (eg. "(char)(char)(char)(char)(char)(char)") string là nhiều char
    double f; // double là số thực, eg 3.14
    long double g; // long double là số thực lớn hơn double eg 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
    bool h; // bool là kiểu dữ liệu logic, chỉ có 2 giá trị là true và false

    // nhap xuat
    // cin>> là nhập
    // cout<< là xuất
    cin>>a; // nhập a, a là int nên mày chỉ nhập đc tối đa 2 tỷ +-, cả dương âm
    cin>>b; // nhập b, b là long long nên mày nhập đc tối đa 9 triệu tỷ +- (18 số 0)
    // vs vector, thì nó là nhiều int hoặc nhiều long long, nên m phải nhập kiểu khác
    // có 2 loại nhập cho vector
    //for each, for each thì nếu vector có kiểu dữ liệu trong khác m cx phải đổi
    // eg vector <char > thì for(char &i:c)
    // eg vector <int > thì for(int &i:c)
    // eg vector <long long > thì for(long long &i:c)
    // bắt buộc phải có dấu & nếu ko thì nhập ko vào, mày có thể thay i thành biến chx có tên
    // eg cc, dmm, nobita
    for(int &i : c) {
        cin>>i;
    }
    // for loop
    for(int i = 0; i < c.size(); i++) {
        cin>>c[i];
    }
    // đến xuất dùng cout<< ngược lại của cin>> thôi
    cout<<a;
    cout<<b;
    for(int i : c) {
        cout<<i<<" "; // dấu cách để ngăn cách các số trong vector
    }
    // nếu m cout thì chúng sẽ liên nhau nên m phải ngăn cách ra
    // thay vì cout<<i; thì sẽ cout<<i<<" " hoặc cout<<i<<"\n" để xuống dòng
    // \n để xuống dòng \" để in ra " " " thay vì bị lỗi
    
}