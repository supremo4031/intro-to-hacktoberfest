#include<bits/stdc++.h>
using namespace std;

#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main()
{
	sup;

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<int, int> m;
        ll b = 0, ans = 0;
        m[0]++;
        for(int i = 0; i < n; i++) {
            b += s[i] - '0';
            ll c = b - (i + 1);
            ans += m[c];
            ++m[c];
        }

        cout << ans << endl;
    }

    return 0;
}
