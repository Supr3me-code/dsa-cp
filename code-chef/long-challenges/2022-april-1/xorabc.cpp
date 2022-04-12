#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;

        ll A = x & ~(x-1);
        if(x&1 || x==A){
            cout<<-1<<endl;
        }else{
            cout<<A/2<<" "<<x/2<<" "<<(x-A)/2<<endl;
        }
    }
    return 0;
}


// -1 for odd numbers
    // for making the sum odd -> out of 3 numbers -> 1 odd 2 even || 3 odd 0 even
    // (a^b) + (b^c) + (c^a)
    // suppose a -> last bit == 1 ---- to make (a^b)==odd -> last bit of b == 0
    // last bit of b == 0 -> if last bit of c == 0 -> (b^c)->odd , (c^a) --> even
    //                       if last bit of c == 1 -> (b^c)->even, (c^a) --> odd
    // therefore, whatever happens, we'll always have 2 odd and 1 even number , and their sum can NEVER be odd.

// -1 for power of 2
    // for power of 2 the only solution is (a=x/2 b=x/2 c=0) OR (a=0 b=0 c=x/2), but a,b,c should be distinct

// for any other number
    // a = 0
    // b = x/2
    // c = b<<1 (remove msb from b)
