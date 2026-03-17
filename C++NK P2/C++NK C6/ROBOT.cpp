#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> cur,next2;
ll dir = -1;

void changeDir(ll x, ll y, ll x1, ll y1){
	if(x1>x) dir = 1;
	else if(y1>y) dir = 0;
	else if(y1<y) dir = 2;
	else dir = 3;
}
pair<ll,ll> nextRight(ll x, ll y){
	switch(dir){
		case 0: return {x+1,y};
		case 1: return {x,y-1};
		case 2: return {x-1,y};
		case 3: return {x, y+1};
	}
	return{};
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
    ll n,val1,val2,cnt=0;
	bool check1 = true,check2 = true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val1>>val2;
		if(check1){
			cur = {val1,val2};
			check1 = false;
			continue;
		} else if(check2){
			changeDir(cur.first,cur.second,val1,val2);
			next2 = nextRight(val1,val2);
			cur = {val1,val2};
			check2 = false;
			continue;
		}
		
		changeDir(cur.first,cur.second,val1,val2);		
		if(val1 == next2.first and val2 == next2.second) cnt++;
		next2 = nextRight(val1,val2);
		cur = {val1,val2};
	}
	cout<<cnt;
    return 0;
}