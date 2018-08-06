#include <queue>
#define DBG(x) cerr << #x << ": " << x << endl;
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

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

int main(){
	int cantEncuestas;
	cin >> cantEncuestas;
	//std::vector<std::vector<char> > matrizEncuestas;
	std::vector<pair<int, int>> encuesta (1000);
	std::vector<int> resultado (cantEncuestas);
	forn(i, 1000){
		encuesta[i].second = i;
		encuesta[i].first = 0;
	}
	forn(i, cantEncuestas){
		int encuestai;
		cin >> encuestai;
		forn(i, 1000){
		encuesta[i].second = i;
		encuesta[i].first = 0;
		}
		forn(j, encuestai){
			int votoEncuesta;
			cin >> votoEncuesta;
			encuesta[votoEncuesta-1].first ++;
		}

		std::sort(encuesta.begin(), encuesta.end());
		int menorMaximo = encuesta[999].second;
		for(int i = 999; encuesta[999].first == encuesta[i].first ; i--){
			if(encuesta[i].second < menorMaximo){
				menorMaximo = encuesta[i].second;
			}
		}
		resultado[i] = menorMaximo+1;
	}

	forn(i, resultado.size()){
		cout << resultado[i] << endl;
	}

}