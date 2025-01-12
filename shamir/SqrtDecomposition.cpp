#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, 10);
#define ll long long
#define ld long double
#define gcd(a, b) __gcd(a, b)
#define lcm(a,b) a/gcd(a,b)*b
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first
#define S second
#define sz(x) (int)x.size()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fore(a, b, c) for(int a=b; a<c; ++a)
#define all(x) x.begin(), x.end()
#define int ll
#define endl '\n';
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#define raya cerr << "==========================" << endl;
const double EPS = 1e-7;
const double PI = acos(-1);
const int MOD = 1e9+7;  
int TC = 0;

struct Sqrt {
    int block_size;
    vector<int> nums;
    vector<int> blocks;
    
    Sqrt(int sqrtn, vector<int> &arr) : block_size(sqrtn), blocks(sqrtn, 0) {
        nums = arr;
        for (int i = 0; i < sz(nums); i++) {
            blocks[i / block_size] += nums[i];
        }
    }

    void update(int x, int v){
        blocks[x / block_size] -= nums[x];
        nums[x] = v;
        blocks[x / block_size] += nums[x];
    }

    int query(int r){
        int res = 0;
        for (int i = 0; i < r / block_size; ++i) { 
            res += blocks[i];
        }
        for (int i = (r / block_size) * block_size; i < r; i++) {
            res += nums[i];
        }
        return res;
    }

    int query(int l, int r){
        return query(r+1) - query(l);
    }

};

void solve(){
    int n, q;
    cin >> n >> q;

    vi arr(n);
    fore(i, 0, n){
        cin >> arr[i];
    }

    Sqrt sq((int)ceil(sqrt(n)), arr);

    for(int i=0; i<q; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int k, u;
            cin >> k >> u;
            sq.update(k-1, u);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sq.query(l, r) << endl;
        }
    }

}
    
signed main(){
    fast;
    int tt = 1;
    // cin >> tt;
    while(tt--){
        TC++;
        solve();
    }
}
