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
	int n;
	std::cin >> n;
	std::vector<int> tamanosPosibles;
	forn(i,3){
		int elemento;
		std::cin >> elemento;
		tamanosPosibles.push_back(elemento);
	} //ya esta la entrada


    std::sort(tamanosPosibles.begin(), tamanosPosibles.end());
	std::vector<int> tamanosPosiblesAux = tamanosPosibles;

    int respuesta(0);
    if(n%tamanosPosibles[0]==0){
    	respuesta = n/tamanosPosibles[0];
    	cout << respuesta << endl;
    	return 0;
    }
    unsigned int i = 1;
    while(i < 3){
    	if( (n-tamanosPosibles[i]	)%tamanosPosibles[0] == 0 ){
    		list
    	}
	    i++;
	}

}