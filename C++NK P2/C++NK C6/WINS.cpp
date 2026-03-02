#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct e{
	int x,y,i;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("WINS.INP", "r")){
        freopen("WINS.INP", "r", stdin);
        freopen("WINS.OUT", "w", stdout);
    }
    int n,x,y,x0,y0, x1,y1,x2,y2;
	cin>>n;
	cin>>x>>y>>x0>>y0;
	vector<e> a={{x0,y,1}};
	for(int i=2;i<=n;i++){
		cin>>x1>>y1>>x2>>y2;
		for(int j = 0; j < a.size(); j++){
			if((a[j].y>=y1 and a[j].y<=y2)
			and (a[j].x>=x1 and a[j].x<=x2)){
				a.push_back({x2,y1,i});
				break;
			}
		}
	}
	cout<<a.size()<<"\n";
	for(int oi=a.size()-1;oi>=0;oi--) cout<<a[oi].i<<" ";
    return 0;
}