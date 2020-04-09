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
		int i, j, k;
		if (a < b)
			i = b;
		else
			i = a;
		//bool ex = false;
		while(1){
			if (i % 2 == 0) {
				j = i / 2;
				if (j % a == 0)
				{
					//ex = true;
					k = j;
					break;
				}
				else
				{
					k = j + 1;
					break;
				}
			}
			else {
				j = (i + 1) / 2;
				if (j % a == 0)
				{
					//ex = true;
					k = j;
					break;
				}
				else
				{
					k = j + 1;
					break;
				}
			}
		}
		cout << j << "\n";
	}
	return 0;
}