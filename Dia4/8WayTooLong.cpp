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
#include <math.h>       /* log10 */


const int MAXN=100100;

int main() {
	
	int n;
	cin >> n;
	std::vector<string> palabras;
	
	forn(i, n){
		string tmp;
		cin >> tmp;
		palabras.push_back(tmp);
	}

	forn(i, n){
		unsigned int x = palabras[i].length();
		if(x <= 10){

			cout << palabras[i] << endl;
		}else{
			int cantLetras = palabras[i].length()-2;

			int aux1 = palabras[i].length();
			cout << palabras[i][0];
			cout << cantLetras << palabras[i][aux1-1] << endl;
		}
	}
}	