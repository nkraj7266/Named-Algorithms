#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fori(a, n) for (int i = (a); i < (n); i++)
#define forj(a, n) for (int j = (a); j < (n); j++)
#define fork(a, n) for (int k = (a); k < (n); k++)
#define each(e, a) for (auto &(e) : (a))
#define pb(a) push_back((a))
#define pr(x) cout << x << endl
#define prs(x) cout << x << ' '
#define br cout << endl

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using mii = map<int, int>;

const double PI = 3.1415926535;
const ll inf = 1e18;
const ll mod = 1000000007;

struct hasher
{
  vector<long long> pHash;
  vector<long long> pk;
  long long n, p, mod;
  void init(string s, long long _p, long long _mod)
  {
    n = s.length(), p = _p, mod = _mod;
    pHash.resize(n);
    pk.resize(n);
    pHash[0] = (s[0] - 'a' + 1) % mod;
    pk[0] = 1;
    for (int i = 1; i < n; i++)
    {
      pHash[i] = (pHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
      pk[i] = (pk[i - 1] * p) % mod;
    }
  }
  long long getpHash(int l, int r)
  {
    if (l == 0)
      return pHash[r];
    return ((pHash[r] - pHash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;
  }
};

long long createHash(string s, int p, int mod)
{
  int n = s.length();
  long long ans = (s[0] - 'a' + 1) % mod;
  for (int i = 1; i < n; i++)
  {
    ans = (ans * p + (s[i] - 'a' + 1)) % mod;
  }
  return ans;
}

void solve()
{
  string s;
  for (int i = 0; i < 10; i++)
    s.push_back('a' + (rand() % 26));
  hasher hash;
  hash.init(s, 31, mod);
  each(e, hash.pHash)
  {
    prs(e);
  }
  br;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}