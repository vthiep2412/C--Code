#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define umap unordered_map
#define uset unordered_set

ll DijkstraFind(ll s, ll e, auto adj, uset<ll>& vis, ll Msum, ll MINI){
    ll tempS = s;
    vis.insert(s);
    for(ll i = 0; i < adj[s].size(); i++){
        if(adj[tempS][i] != 0){
            if(i == e){
                Msum += adj[tempS][i];
                MINI = min(MINI, Msum);
                return MINI;
            }
            if(vis.insert(i).second){
                Msum += adj[tempS][i];
                MINI = min(MINI, DijkstraFind(i, e, adj, vis, Msum, MINI));
                Msum -= adj[tempS][i]; // Reset Msum when backtracking
            }
        }
    }
    return MINI;
}
/*
ll DijkstraFind(ll s, ll e, auto adj, uset<ll>& vis, ll Msum, ll MINI){
    cout << "[DEBUG] Entering DijkstraFind: s=" << s << ", e=" << e 
         << ", Msum=" << Msum << ", MINI=" << MINI << endl;

    ll tempS = s;
    vis.insert(s);
    cout << "[DEBUG] Marked node " << s << " as visited." << endl;

    for(ll i = 0; i < adj[s].size(); i++){
        cout << "[DEBUG] Checking adj[" << tempS << "][" << i << "] = " << adj[tempS][i] << endl;

        if(adj[tempS][i] != 0){
            if(i == e){
                cout << "[DEBUG] Destination node " << e << " found via " << tempS 
                     << ", edge weight = " << adj[tempS][i] << endl;
                Msum += adj[tempS][i];
                cout << "[DEBUG] Total path sum = " << Msum << endl;
                MINI = min(MINI, Msum);
                cout << "[DEBUG] Updated MINI = " << MINI << ". Returning from path." << endl;
                return MINI;
            }

            if(vis.insert(i).second){
                cout << "[DEBUG] Exploring unvisited neighbor " << i << ", edge weight = " 
                     << adj[tempS][i] << endl;
                Msum += adj[tempS][i];
                cout << "[DEBUG] Added edge to Msum, now Msum = " << Msum << endl;
                MINI = min(MINI, DijkstraFind(i, e, adj, vis, Msum, MINI));
                cout << "[DEBUG] Back from recursion at " << i << ", MINI = " << MINI << endl;
                Msum -= adj[tempS][i];
                cout << "[DEBUG] Backtracking: subtracted edge weight, Msum = " << Msum << endl;
            } else {
                cout << "[DEBUG] Neighbor " << i << " already visited. Skipping." << endl;
            }
        }
    }

    cout << "[DEBUG] Exiting DijkstraFind: s=" << s << ", MINI=" << MINI << endl;
    return MINI;
} */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uset<ll> vis;
    ll Msum = 0;
    ll MINI = INT_MAX;

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
    }
    ll start, end;
    cin>>start >> end;
    cout<<DijkstraFind(start, end, adj, vis, Msum, MINI);
}