#include<bits/stdc++.h>
using namespace std;

#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

vector<vector<ll>> adj;
vector<ll> v, win, vis;

char c;

void dfs(ll u) {
    vis[u] = 1;
    ll f = 0;
    for(ll v : adj[u])
        if(!vis[v])
            dfs(v);
    for(ll v : adj[u])
        if(!win[v]) {
            f = 1;
            break;
        }
    if(f)
        win[u] = 1;
}


int main()
{
	sup;

    ll n;
    cin >> n;
    adj = vector<vector<ll>> (n + 1);
    v = vector<ll> (n + 1);
    win = vector<ll> (n + 1);
    vis = vector<ll> (n + 1);

    for(int i = 1; i <= n; i++) 
        cin >> v[i];

    for(int i = 1; i <= n; i++) {
        ll a = v[i];
        for(int j = i + a; j <= n; j += a) {
            if(v[j] > a)
                adj[i].push_back(j);
        }

        for(int j = i - a; j >= 1; j -= a) {
            if(v[j] > a)
                adj[i].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i);
    
    string s;
    for(int i = 1; i <= n; i++) {
        if(win[i])
            s += 'A';
        else 
            s += 'B';
    }

    cout << s << endl;
    
    return 0;
}