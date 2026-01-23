#include <bits/stdc++.h>
using namespace std;

int ctoi(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else {
        throw invalid_argument("Input character is not a digit.");
    }
}

vector<pair<int,string>> compressVector(string str) {
    vector<pair<int,string>> v;
    int cnt = 1;
    for (int i = 0; i < str.size(); i++) {
        if (i > 0 && str[i-1] == str[i]) {
            cnt++;
        } else {
            if (i > 0) {
                while (cnt > 9) {
                    v.push_back(make_pair(9, string(1, str[i-1])));
                    cnt -= 9;
                }
                v.push_back(make_pair(cnt, string(1, str[i-1])));
            }
            cnt = 1;
        }
    }
    if (cnt > 0) {
        while (cnt > 9) {
            v.push_back(make_pair(9, string(1, str.back())));
            cnt -= 9;
        }
        v.push_back(make_pair(cnt, string(1, str.back())));
    }
    return v;
}

vector<pair<int,string>> compressVectorWithLimit(string str, int limit = 9) {
    vector<pair<int,string>> v;
    int cnt = 1;
    for (int i = 0; i < str.size(); i++) {
        if (i > 0 && str[i-1] == str[i]) {
            cnt++;
            if (cnt > limit) {
                v.push_back(make_pair(limit, string(1, str[i-1])));
                cnt = 1;
            }
        } else {
            if (i > 0) {
                v.push_back(make_pair(cnt, string(1, str[i-1])));
            }
            cnt = 1;
        }
    }
    if (cnt > 0) {
        v.push_back(make_pair(cnt, string(1, str.back())));
    }
    return v;
}
string compressVectortoStr(string str)
{
    vector<pair<int,string>> compress = compressVector(str);
    string strReturn;
    for(int i=0;i<compress.size();i++)
    {
        strReturn+=to_string(compress[i].first);
        strReturn+=compress[i].second;
    }
    return strReturn;
}

string DecompressStr(string str)
{
    string strReturn;
    int cntNC=0,Dbcnt=0,cnt;
    for(int i=0;i<str.size();i++)
    {
        if(isdigit(str[i-1])&&!isdigit(str[i])&&i>0)
        {cntNC++;}
        if(!isdigit(str[i-1])&&!isdigit(str[i])&&i>0)
        {Dbcnt++;}
    }
    if(Dbcnt>0){return "not compressed string";}
    else if (cntNC>0&&Dbcnt==0)//cntNC>0&& ko hoat dong binh thuong sua sau!
    {
        for(int i=0;i<str.size();i+=2)
        {
            cnt=ctoi(str[i]);
            for(int j=0;j<cnt;j++)
            {
                strReturn+=str[i+1];
            }
        }
    }
    return strReturn;
}

string DecompressStr2(string str) {
    string strReturn;
    int i = 0;
    while (i < str.size()) {
        if (isdigit(str[i])) {
            int cnt = 0;
            // Xử lý trường hợp có nhiều chữ số liên tiếp
            while (i < str.size() && isdigit(str[i])) {
                cnt = cnt * 10 + ctoi(str[i]);
                i++;
            }
            // Kiểm tra nếu có ký tự sau số
            if (i < str.size() && isalpha(str[i])) {
                strReturn.append(cnt, str[i]);
                i++;
            } else {
                return "not compressed string";
            }
        } else {
            return "not compressed string";
        }
    }
    return strReturn;
}

int main()
{
    string a,b,c;
    getline(cin,a);
    b = compressVectortoStr(a);
    cout<<b<<endl;
    cout<<DecompressStr(b);
    return 0;
}