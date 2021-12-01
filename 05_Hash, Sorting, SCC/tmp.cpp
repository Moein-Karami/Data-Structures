#include <bits/stdc++.h>

using namespace std;

int main()
{
	double x, y;

	cin >> x >> y;
	for (int i = 1; i <= 1000000; i++)
	{
		x = (x + y) / 2.0;
		y = sqrt(x * y);
	}
	cout << fixed << setprecision(4) << x << " " << y << endl;
}