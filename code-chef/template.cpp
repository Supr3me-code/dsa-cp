#include <bits/stdc++.h>


using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int

#define ld long double
#define forn(i, x, n) for (ll i = x; i < n; i++)
#define fornb(i, n, x) for (ll i = n; i >=x; i--)
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define MOD 1000000007
#define MAX 3000007
#define endl "\n" // REMOVE in lleraction problem
#define debug cout << "K"
vector<ll> visited(MAX) ,visited2(MAX), color(MAX), dist(MAX, -1);
vector<ll> graph[MAX];
vector<ll> parent(MAX);
vector<pii> graph2[MAX];


bool sortbysecasc(const pair<ll, ll> &a,
                   const pair<ll, ll> &b)
{

    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
        return a.first < b.first;
}



struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll isKthBitSet(ll n, ll k)
{
    if (n & (1ll << (k)))
        return 1;
    else
        return 0;
}

// Function to return LCM of two numbers
long long lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

ll log_a_to_base_b(ll a, ll b)
{
    return log(a) / log(b);
}



bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    ll v = sqrt(n);
    for (ll i = 2; i <= v; i++)
        if (n % i == 0)
            return false;

    return true;
}

long long moduloMultiplication(long long a,
                               long long b,
                               unsigned long long mod)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}

ll largestPower(ll n, ll p)
{   ll x = 0;

    while (n)
    {
        n /= p;
        x += n;
    }
    return x;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}



void SieveOfEratosthenes(ll n, set<ll> &st)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            st.insert(p);
}




ll CeilIndex(std::vector<ll>& v, ll l, ll r, ll key)
{
    while (r - l > 1) {
        ll m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}


ll LongestIncreasingSubsequenceLength(vector<ll>& v)
{
    if (v.size() == 0)
        return 0;
 
     vector<ll> tail(v.size());

    ll length = 1; // always polls empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 0; i < v.size(); i++) {
 
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }

    return length;
}



bool isPowerOfTwo(ll x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

ll node_cnt(ll node)
{
    if (visited[node])
        return 0;

    visited[node] = true;

    ll a = 0;

    for (auto child : graph[node])
    {
        // cout<<node<<" "<<child<<" ";
        if (!visited[child])
            a += node_cnt(child) + 1;
    }

    return a;
}
unsigned long long modInverse(unsigned long long n,
                              ll p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;

    ll res = 1;

    // Use Sieve of Eratosthenes to find all primes
    // smaller than n
    bool isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));
    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

    // Consider all primes found by Sieve
    for (ll i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            // Find the largest power of prime 'i' that divides n
            ll k = largestPower(n, i);

            // Multiply result with (i^k) % p
            res = (res * power(i, k, p)) % p;
        }
    }
    return res;
}

ll log22(ll n)
{
    ll a = __builtin_clzll(n);
    return 63-a;
}

ll Ispalindrome(string &s)
{
    ll n = s.size();
    ll fl = 0;
    forn(i, 0, n / 2)
    {
        if (s[i] != s[n - i - 1])
            return 0;
    }

    return 1;
}

ll isSorted(vector<ll> A)
{

    ll n = A.size();
    forn(i, 0, n - 1)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}
ll BinarySearchUminus(ll val, vector<ll> &A)
{
    ll low = 0, high = A.size() - 1;

    while (high > low)
    {
        ll mid = (low + high + 1) / 2;
        if (A[mid] == val)
            low = mid; // high = mid-1 for lower_bound-1
        else if (A[mid] < val)
            low = mid;
        else
            high = mid - 1;
    }
    if (A[low] > val)
        return -1;
    return low;
}

ll Ceil(ll a, ll b)
{
    ll ans = a / b;
    if (a % b != 0)
        ans++;
    return ans;
}



void bfs(queue<ll> &q )
{


    while (!q.empty())
    {
        ll v = q.front();

        q.pop();
        for (ll e : graph[v])
        {
            if (dist[e] == -1)
            {

                dist[e] = dist[v] + 1;

                
                q.push(e);
                
            }
        }
    }
    
}

void dijkstra(ll s, vector<ll> & d, vector<ll> & p , ll n) {
    d.assign(n, 1e17);
    p.assign(n, -1);

    d[s] = 1e17;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({1e17, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : graph2[v]) {
            ll to = edge.first;
            cout<<to<<" "<<d[v]<<" "<<edge.second<<endl;
            ll len =min(d[v] , edge.second);

            if (len < d[to]) {
                d[to] =len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void primeFactors(ll n , vector<ll> &Cnt)
{
    // Prll the number of 2s that divide n
    while (n % 2 == 0)
    {
        Cnt.push_back(2);
        n = n/2;
    }
 
    // n must be odd at this poll. So we can skip
    // one element (Note i = i +2)
    ll v = sqrt(n);
    for (ll i = 3; i <= v; i = i + 2)
    {
        // While i divides n, prll i and divide n
        while (n % i == 0)
        {
            Cnt.push_back(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    Cnt.push_back(n);
}
void printDivisors(ll n ,  vector<ll> &a)
{
    // Note that this loop runs till square root
    ll sqr = sqrt(n);
    for (ll i=1; i<=sqr; i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
            a.push_back(i);
                // cout <<" "<< i;
 
            else // Otherwise print both
            {
            a.push_back(n/i);
            
            a.push_back(i);
            }
                // cout << " "<< i << " " << n/i;
        }
    }
    sort(all(a));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ll t=1;
    cin>>t;
    while (t--){
       
    }
}