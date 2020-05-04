#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, price, wrap;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++) {
			cin >> price >> wrap;
			pair<int, int> p;
			p.first = price;
			p.second = wrap;
			v.push_back(p);
		}
		int sum = 0;
		int temp = 0;
		for (int i = 0; i < N;) {
			int one=0, two=0, three=0;
			if (i + 1 < N)
			{
				one = v[i].first < v[i + 1].first ? v[i].first : v[i + 1].first;
				two = v[i].first < v[i + 1].first ? v[i].first : v[i + 1].first; +v[i + 1].second;
				int mtwo = v[i].first + v[i + 1].first - two;
				if (i + 2 < N)
				{
					three = one < v[i + 2].first ? one : v[i + 2].first + v[i + 1].second + v[i + 2].second;
					int mthree = v[i].first + v[i + 1].first + v[i + 2].first - three;
					temp = mtwo < mthree ? mtwo : mthree;
					if (temp > 0)
					{
						if (temp == mtwo)
						{
							i += 2;
							sum += two;
						}
						else if (temp == mthree)
						{
							i += 3;
							sum += three;
						}
					}
					else i++;
					sum += one;
				}
				else
				{
					if (mtwo > 0)
					{
						i += 2;
						sum += two;
					}
					else
					{
						i++;
						sum += one;
					}
				}
			}
			sum += v[i].first;
			i++;
		}
		for (int i = 0; i < N; i++) {
			sum += v[i].first;

		}
		cout << sum << "\n";
	}
}