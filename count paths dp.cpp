#include<bits/stdc++.h>
using namespace std;

#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll n, m, k, cnt = 0;
vector<vector<ll>> adj(105);
vector<vector<ll>> dp(105, vector<ll> (105, -1));

ll dfs(ll v, ll c) {
    cnt++;
    if(c > k)
        return 1;
    if(dp[v][c] != -1)
        return dp[v][c];
    ll paths = 0;
    for(ll u : adj[v])
        paths += dfs(u, c + 1);

    return dp[v][c]= paths;
}

int main()
{
	sup;

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
        ans += dfs(i, 1);

    cout << ans << endl;
    
    
    return 0;
}