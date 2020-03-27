#include <iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int maxF, maxS;
vector<int> countt;
void func(int i,int J, vector<int> arr[10001], vector<pair<int, int>> p,int c) {
	c++;
	int tmp = arr[i][J];
	i=p[tmp].second - p[tmp].first + i;

	if (maxS<i&&i<= maxF)
		countt.push_back(c);
	else
		for (int j = 0; j < arr[i].size(); j++)
		{
			func(i, j, arr, p,c);
		}
}
int main() {
	std::ios::sync_with_stdio(false);
	int T, n, S, F;
	string s;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> arr[10001];
		vector<pair<int, int>> p;
		p.resize(n);
		maxF = 0;
		maxS = 0;
		for (int i = 0; i < n;i++) {
			cin >> s >> S >> F;
			p[i].first = S;
			p[i].second = F;
			arr[S].push_back(i);
			arr[F].push_back(i);
			if (maxF < F)
				maxF = F; maxS = S;
		}

		int c = 0;
		
		int ntimes = n;
		bool ex = false;
		for (int i = 0; i < 10001; i++) {
			if (arr[i].size() != 0)
			{
				for (int j = 0; j < arr[i].size(); j++)
				{
					c = 0;
					func(i,j, arr, p,c);
					n--;
					if (n == 0)
					{
						ex = true;
						break;
					}
				}
			}
			if (ex)
				break;
		}

		int max = 0;
		for (int i = 0; i < countt.size(); i++)
			if (countt[i] > max)
				max = countt[i];
		cout << max << "\n";
		while(countt.size())
			countt.pop_back();
	}
	return 0;
}