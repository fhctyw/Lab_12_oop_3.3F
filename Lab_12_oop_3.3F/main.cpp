#include <iostream>
#include "PubicCursor.h"
#include "PrivateCursor.h"
using namespace std;

int main()
{
	PubicCursor pc({100, 100}, 3, 0);
	pc.move(10, 10);
	cout << pc << endl;
	
	PrivateCursor pc1({ 0, 0 }, 10, 1);
	pc1.move(200, 200);
	cout << pc1 << endl;

	return 0;
}