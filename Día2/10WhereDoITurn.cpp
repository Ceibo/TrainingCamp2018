#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	long long Ax,Ay,Bx,By,Cx,Cy,ABx,ABy,BCx,BCy,test;

	cin >> Ax;
	cin >> Ay;
	cin >> Bx;
	cin >> By;
	cin >> Cx;
	cin >> Cy;

	ABx = Bx-Ax;
	ABy = By-Ay;
	BCx = Cx-Bx;
	BCy = Cy-By;

	if( (test = BCx*ABy - BCy * ABx) == 0 ){
		cout << "TOWARDS";
	}else if(test>0)
		cout << "RIGHT" ;
	else 
		cout << "LEFT";
	

	return 0;
}
