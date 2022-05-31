#include<bits/stdc++.h>
using namespace std;

struct Movie{
    int size;
    int rating;
};

bool comparator(Movie movie1, Movie movie2){
    if(movie1.rating>movie2.rating) return true;
    return false;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;

        Movie movie[n];
        for(int i=0;i<n;i++){
            cin>>movie[i].size>>movie[i].rating;
        }
        sort(movie, movie+n, comparator);

        int result;
        for(int i=0;i<n;i++){
            if(movie[i].size<=x){
                result = movie[i].rating;
                break;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}