#include <iostream>
#include <algorithm>

#define DBG(x) cerr << #x << "=" << (x) << '\n'


using namespace std;

int main(void)
{
	long long max=0,min=0;
	int length,sum,sum_total,i,ten;
	
	ios::sync_with_stdio(false);

	cin >> length;
	cin >> sum_total;

	if(sum_total == 0){
		cout << -1 << ' ';
		cout << -1 << '\n';
		return 0;
	}

	sum = sum_total;
	for(i=0;sum>9 && i<length-1;i++){
		max = max*10 +9;
		sum -= 9;
	}
	if( sum>9 ){
		cout << -1 << ' ';
		cout << -1 << '\n';
		return 0;
	}
		
	if( i<length && sum<10){
		max = max*10 +sum;
		i++;
	}
	if( i<length ){
		for(;i<length;i++)
			max *= 10;
	}
	sum = sum_total;
	sum --;	//MS digit
	ten = 1;
	for(i=0 ; i<length-1 && sum>8 ; i++){
		min += (9*ten);
		sum -= 9;
		ten *=10;
	}
	if(i == length-1){
		min += ((sum+1)*ten);
		sum = 0;
	}else{
		min += sum*ten;
		for(;i<length-1;i++)
			ten *=10;
		min += ten;
	}
	
cout << min << " ";
cout << max << '\n';

	return 0;
}
