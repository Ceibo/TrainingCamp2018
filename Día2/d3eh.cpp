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

int main(void)
{
	long apps,t_app,events,n_events;
	long unread=0;
	int t_event;
	vector<pair<long,pair<long,bool> > > total;
	vector<int> resultado;

	ios::sync_with_stdio(false);

	cin >> apps;
	cin >> n_events;

	std::vector<std::vector<pair<int,bool> > > matrizApps;
	forn(i, apps){
		std::vector<pair<int,bool> >vectorApps;
		matrizApps.push_back(vectorApps);
	}
	
	for(events = 0;events < n_events;events++){
		cin >> t_event;
		cin >> t_app;
		if( t_event == 1){
			total.push_back(make_pair(matrizApps[t_app-1].size(),make_pair(t_app,false)));
			matrizApps[t_app-1].push_back(make_pair(total.size()-1,false));
			unread++;
		}else if (t_event == 2){
			int cuantosLei(0);
			for(unsigned int i = 0; i < matrizApps[t_app-1].size(); i++){
				if(not matrizApps[t_app-1][i].second){
					int id_total = matrizApps[t_app-1][i].first;
					total[id_total] = make_pair(id_total,make_pair(t_app,true));
					cuantosLei++;
					matrizApps[t_app-1][i] = make_pair(total[id_total].first,true);	
				}

			}	
			unread = unread - cuantosLei;
		}else{
			int cuantosLei(0);
			for(int i = 0; i < t_app; i++){
				if(not total[i].second.second){
					matrizApps[total[i].second.first-1][total[i].first] = make_pair(i, true);
					total[i] = make_pair(total[i].first, make_pair(total[i].second.first,true));
					cuantosLei++;

				}

			}
			unread = unread - cuantosLei;
		}
		resultado.push_back(unread);	
	}
	for(int i = 0; i < resultado.size();i++){
		cout << resultado[i] << '\n';
	}

	return 0;
}
