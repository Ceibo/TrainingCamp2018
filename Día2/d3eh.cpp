#include <iostream>
#include <algorithm>
#include <queue>

#define DBG(x) cerr << #x << ": " << x << endl;

using namespace std;

int main(void)
{
	long apps,t_app,events,n_events;
	long unread=0;
	int t_event;
	vector<pair<long,bool>> total;

	ios::sync_with_stdio(false);

	cin >> apps;
	cin >> n_events;
	
	for(events = 0;events<n_events;events++){
		cin >> t_event;
		cin >> t_app;
		if( t_event == 1){
			total.push_back(make_pair(t_app,false));
			unread++;
		}else if (t_event == 2){
			for(long i=0;i<total.size();i++){
				if(t_app == total[i].first){
					if(false == total[i].second){
						total[i].second = true;
						unread--;
					}
				}
			}
		}else{
			for(long i=0;i<t_app;i++){
				if(false == total[i].second){
					total[i].second = true;
					unread--;
				}
			}
		}
		cout << unread << '\n';	
	}

	return 0;
}
