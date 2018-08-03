#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define DBG(x) cerr << #x << ": " << x << endl;
#define uppercase(x) ((((x)<='z') && (x)>=('a'))?(x)+('A'-'a'):(x))

using namespace std;



int main(void)
{
	char c_read;
	unordered_set<char> chars_total;
	vector<char> total_digits; // M 0 D 1 C 2 L 3 X 4 V 5 I 6
	
	total_digits
	while(cin >> c_read && c_read!='\n'){
		chars_total.insert(uppercase(c_read));
	}
	total_digits[0] = 


	return 0;
}
