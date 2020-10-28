#include<bits/stdc++.h>
using namespace std;

#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main()
{
	sup;
    
    ll m, n, curidx = 0;
    cin >> m;
    map<ll, ll> check;
    vector<ll> idx(m + 1), lar(m + 1), car(m + 1);
    for(int i = 0; i < m; i++) {
        ll t, x, l, c;
        cin >> t;
        if(t == 1) {
            cin >> x;
            idx[i] = curidx, lar[i] = 1, car[i] = 0;
            check[curidx] = x;
            curidx++;
        }
        else {
            cin >> l >> c;
            idx[i] = curidx, lar[i] = l, car[i] = c;
            curidx += l * c;
        }
    }
    
    cin >> n;
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        --tmp;
        if(check.find(tmp) != check.end())
            ans[i] = check[tmp];
        else {
            ll idxfind = -1;
            while(check.find(tmp) == check.end()) {
                ll start = 0, end = m - 1;
                ll idxans = 0;
                while(start <= end) {
                    ll mid = (start + end) / 2;
                    if(tmp >= idx[mid] && tmp < idx[mid] + lar[mid] * car[mid]) {
                        idxans = mid;
                        break;
                    }
                    if(tmp < idx[mid])
                        end = mid - 1;
                    else 
                        start = mid + 1;
                } 
                idxfind = (tmp - idx[idxans]) % lar[idxans];
                tmp = idxfind;           
            }
            ans[i] = check[tmp];
        }
    }

    for(ll &i : ans)
        cout << i << " ";
    cout << endl;


    
    return 0;
}