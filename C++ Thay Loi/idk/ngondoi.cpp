#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("NGONDOI.INP","r",stdin);
	freopen("NGONDOI.OUT","w",stdout);
	int n,ans;
	ans=0;
	cin>>n;
	int a[10000]={0};
	for(int i=1; i<=n; i++) cin>>a[i];
	
	for(int i=2; i<n; i++ )
	{
		if(a[i]>a[i-1] && a[i]>a[i+1]) ans++;
	}
	cout <<ans;

	return 0;
}