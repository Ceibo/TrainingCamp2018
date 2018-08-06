//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <numeric>

const int MAXN=100100;
int n;

int main() {
    ios::sync_with_stdio(0);
    int n; 
    cin >> n;
    int k;
    cin >> k;

    std::vector<int> subVectorKDistintos;
    std::vector<int> kprimeros;
    std::vector<int> kprimerosAux;
    forn(i, k+1){
    	kprimeros.push_back(i+1);
    }
    kprimerosAux = kprimeros;
    std::sort(kprimerosAux.rbegin(), kprimerosAux.rend());

    int j1(0);
    int j2(0);
    forn(i, k+1){
    	if(i%2 == 0){
    		subVectorKDistintos.push_back(kprimeros[j1]);
    		j1++;
    	}else{
    		subVectorKDistintos.push_back(kprimerosAux[j2]);
    		j2++;
    	}
    }



    forn(i, subVectorKDistintos.size()){
    	cout << subVectorKDistintos[i] << " ";
    }
    for(int i = subVectorKDistintos.size(); i < n; i++){
    	if( i != n-1){
    		cout << i+1 << " ";
    	}else{
    		cout << i+1;
    	}
    }

    return 0;
}
