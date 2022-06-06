#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

struct xor1{
    int a;
    int b;
    int thierXOR;
}l;

bool areDistinct(int a, int b, int c, int d){
    if(a==b) return false;
    if(a==c) return false;
    if(a==d) return false;
    if(b==c) return false;
    if(b==d) return false;
    if(c==d) return false;
    return true;
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll l,r;cin>>l>>r;
        int len = r-l+1;
        int len1 = len - 1;
        int pairs = (len1 * (len1+1))/2;
        xor1 bank[pairs];
        int idx = 0;
        for(int i=l;i<r;i++){
            for(int j=i+1;j<=r;j++){
                bank[idx].a = i;
                bank[idx].b = j;
                bank[idx].thierXOR = i^j;
                idx++;
            }
        }

        vector<int> res;
        for(int i=0;i<pairs-1;i++){
            for(int j=i+1;j<pairs;j++){
                if(bank[i].thierXOR == bank[j].thierXOR){
                    if(areDistinct(bank[i].a, bank[i].b, bank[j].a, bank[j].b)){
                        res.push_back(bank[i].a);
                        res.push_back(bank[i].b);
                        res.push_back(bank[j].a);
                        res.push_back(bank[j].b);
                    }
                }
            }
        }

        if(res.size()!=0){
            for(int i=0;i<4;i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}