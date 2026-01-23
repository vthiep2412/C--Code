#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PAY.inp","r",stdin);
	freopen("PAY.out","w",stdout);
	ll x1,x2,x3,x4;
	cin>>x1>>x2>>x3>>x4;
	ll n,sum=0,tmp;
	cin>>n;
	tmp=n-50;
	if(tmp<0){
		cout<<n*x1;
		return 0;
	}
	sum+=50*x1;
//	cout<<"sum "<<sum<<"\n";
	tmp-=50;
	if(tmp<0){
		cout<<n*x2+sum;
		return 0;
	}
	sum+=50*x2;
//	cout<<"sum "<<sum<<"\n";
	tmp-=100;
	if(tmp<0){
		cout<<n*x3+sum;
		return 0;
	}
	sum+=100*x3;
//	cout<<"sum "<<sum<<"\n";
	cout<<tmp*x4+sum;
	return 0;
}