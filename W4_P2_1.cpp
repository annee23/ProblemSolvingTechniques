#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int func(int i) {
	switch (i) {
	case 1: return 3;
	case 2: return 2;
	case 3: return 5;
	case 4: return 2;
	case 5: return 3;
	case 6: return 4;
	case 7: return 5;
	default: return i - 2;
	}
}
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
		if (x == x1 && y == y1)
		{
			cout << 0 << "\n";
			continue;
		}
		int big, sub, small, sum = 0;
		if (a < b)
		{
			big = b; small = a;
		}
		else
		{
			big = a; small = b;
		}
		if (small == 0)
		{
			sum += func(big);
		}
		else
		{
			if (small * 2 < big)
			{
				sum = small;
				sub = big - small * 2;
				sum += func(sub);
			}

			else {
				cout << "not yet\n";
			}
		}
		//if (L - x1 < 2 || L - x < 2 || L - y < 2 || L - y1 < 2)
			//sum += 2;
		cout << sum << "\n";

		
	}
	return 0;
}