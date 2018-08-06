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
    	pair<int, char> auxPar;
    	auxPar.second = alphabet[i];
    	auxPar.first = 0;
    	resultado.push_back(auxPar);
    }

	for(unsigned int i = 0; i < linea.size(); i++){
		forn(j, 26){
			if(linea[i] == alphabet[j]){
				resultado[j] = make_pair(resultado[j].first+1,resultado[j].second);
			}
		}
	}
	sort(resultado.begin(), resultado.end());

    pair<bool, char> respuesta;
    respuesta = make_pair((resultado[25].first != resultado[24].first),resultado[25].second);

    return respuesta;
}


char desplazar(char letra, int distancia){
	int res = (((letra-'A' - distancia) %26) + 26) %26;
	std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'A');

    char abc = alphabet[res];
	return abc;
}

int main(){
	int cantLineas;
	cin >> cantLineas;
	cantLineas ++;
	std::vector<string> diario;
	forn(i, cantLineas){
		string aux;
		std::getline(std::cin, aux);
		diario.push_back(aux);
	}

	for(int i = 1; i < diario.size(); i++){
		pair<bool, char> parAux = maxApariciones(diario[i]);
		int distancia;
		if(parAux.first == false){
			cout << "NOT POSSIBLE" << endl;
		}else{
			int distanciaAux = -parAux.second + 'E';
			distanciaAux = distanciaAux*(-1);
			distancia = ((distanciaAux %26) + 26) %26;
			string stringAux = diario[i];
			forn(j, diario[i].size()){
				if(stringAux[j] != ' '){
					stringAux[j] = desplazar(diario[i][j],distancia);
				}
			}

			cout << distancia;
			cout << " ";
			forn(j,diario[i].size()){
				cout << stringAux[j];
			}
		}
		cout << endl;

	}
	return 0;
	
}