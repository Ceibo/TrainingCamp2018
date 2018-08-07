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
#define dprint(v) cout << #v"=" << v << endl

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <numeric>


const int MAXN=100100;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int> > datosPersonas;
	forn(i, n){
		std::vector<int> aux;
		int id;
		cin >> id;
		aux.pb(id);

		int salary;
		cin >> salary;
		aux.pb(salary);

		int childrens;
		cin >> childrens;
		aux.pb(childrens);

		string civilStatus;
		cin >> civilStatus;
		string single("single");
		int status;
		if(civilStatus.compare(single) == 0){
			status = 1;
		}else{
			status = 0;
		}
		aux.pb(status);

		int age;
		cin >> age;
		aux.pb(age);

		datosPersonas.pb(aux);
	}

	std::vector<pair<int, int>> rankingSalarios;

	forn(i, n){
		int salarioi(0);
		if( (datosPersonas[i][3]) == 1 && (datosPersonas[i][2] < 4) && (datosPersonas[i][2] > 0) && (datosPersonas[i][4] <= 40) && (datosPersonas[i][4] >= 30)){
			salarioi = datosPersonas[i][1]*0.85;
			salarioi =  salarioi - (salarioi*abs(4-datosPersonas[i][2])*0.01);
		}
		pair<int, int> aux1 = make_pair(salarioi, datosPersonas[i][0]); 
		rankingSalarios.pb(aux1);
	}
	sort(rankingSalarios.begin(), rankingSalarios.end());

	int tam = rankingSalarios.size();
	int idMaxSalario = rankingSalarios[tam-3].second;
	cout << idMaxSalario;
    return 0;
}
