#include <queue>
#define DBG(x) cerr << #x << ": " << x << endl;
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <numeric>



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
#define uppercase(x) ((((x)<='z') && (x)>=('a'))?(x)+('A'-'a'):(x))

pair<bool, char> maxApariciones(string linea){
	
	std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'A');
    std::vector<pair<int, char>> resultado;
    forn(i, 26){
    	resultado[i].second = alphabet[i];
    	resultado[i].first = 0;
    }

	for(unsigned int i = 0; i < linea.size(); i++){
		forn(j, 26){
			if(linea[i] == alphabet[j]){
				resultado[j].first++;
			}
		}
	}
	sort(resultado.begin(), resultado.end());

    pair<bool, char> respuesta;
    respuesta.second = resultado[25].second;
    respuesta.first = (resultado[25].first != resultado[24].first);

    return respuesta;
}


char desplazar(char letra, int distancia){
	char res = (letra-'A' + distancia)%26;
	return res;
}

int main(){
	int cantLineas;
	cin >> cantLineas;
	std::vector<string> diario;
	forn(i, cantLineas){
		string aux;
		cin >> aux;
		diario.push_back(aux);
	}

	forn(i, diario.size()){
		pair<bool, char> parAux = maxApariciones(diario[i]);
		int distancia;
		if(parAux.first == false){
			cout << "NOT POSSIBLE" << endl;
		}else{
			int distanciaAux =  'E' - parAux.second;
			distancia = distanciaAux%26-1;

			string stringAux = diario[i];
			forn(j, diario[i].size()){
				stringAux[j] = desplazar(diario[i][j],distancia);
			}
			
			cout << distancia << " "; 
			forn(j,diario[i].size()){
			cout << stringAux[j];
			}
		}
		cout << endl;

	}
	return 0;
}