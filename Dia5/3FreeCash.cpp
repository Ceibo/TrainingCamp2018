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

int horarios[100000];

int main(){
	int n;
	cin >> n;
	forn(i, n){
		int a(0);
		int b(0);
		cin >> a;
		cin >> b;
		int tmp = 100*a + b;
		horarios[tmp] ++;
		}
	sort(horarios, horarios+100000);
	cout << horarios[99999];
	return 0;
}