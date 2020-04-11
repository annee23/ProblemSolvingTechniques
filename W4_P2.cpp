#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	int L, x, y, x1, y1;
	int a, b;
	while (T--) {
		cin >> L;
		cin >> x >> y;
		cin >> x1 >> y1;
		a = abs(x - x1);
		b = abs(y - y1);
		int i, j, k, s;
		if (a < b)
		{
			i = b; s = a;
		}

		else
		{
			i = a; s = b;
		}
		//bool ex = false;
		if (x == x1 && y == y1)
			cout << 0 << "\n";
		else {
			if (i % 2 == 0) {
				j = i / 2;
				if (j % a == 0)
				{
					//ex = true;
					k = j;

				}
				else
				{
					int t = abs(j - s);
					k = j + (t / 2)+1;


				}
			}
			else {
				j = (i + 1) / 2;
				if (j % a == 0)
				{
					//ex = true;
					k = j;

				}
				else
				{
					int t = abs(j - s);
					k = j + (t / 2)-1;

				}
			}

			cout << k << "\n";
		}
	}
	return 0;
}