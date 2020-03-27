#include <iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T;
	string S, R;
	cin >> T;
	while (T--) {
		cin >> S;
		cin >> R;
		vector<vector<int>>v;
		v.resize(R.size());
		vector<int>r;
		r.resize(R.size());
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < R.size(); j++) {
				if (S[i] == R[j])
				{
					v[j].push_back(i);
					r[j]++;
					break;
				}
			}
		}
		bool boo = false;
		for(int i=0;i<R.size();i++)
			if (v[i].size() == 0)
			{
				cout << "0\n";
				boo = true;
				break;
			}
		if (boo)
			continue;
		int min = 15000, mini = 0;
		for (int i = 0; i < r.size(); i++) {
			if (min > r[i])
			{
				min = r[i];
				mini = i;
			}
		}
		int minofmax = 15000;
		min = 15000;  vector<pair<int,int>>mink; pair<int,int> t;
		for (int i = 0; i < v[mini].size(); i++) {
			for (int j = 0; j < R.size(); j++) {
				for (int k = 0; k < v[j].size(); k++)
					if (abs(v[mini][i] - v[j][k]) < min)
					{
						min = abs(v[mini][i] - v[j][k]);
						t.first = j;
						t.second = k;
					}
				mink.push_back(t);
			}
			int max = 0; int pm = 0;
			for(int k=0;k<mink.size();k++)
				if (max < abs(v[mini][i] - v[mink[k].first][mink[k].second]))
				{
					max = abs(v[mini][i] - v[mink[k].first][mink[k].second]);
					if (v[mini][i] - v[mink[k].first][mink[k].second] > 0)
						pm = 1;
					else
						pm = 2;

				}
			if (pm == 1)
			{
				int max2 = 0;
				for (int k = 0; k < mink.size(); k++)
					if (v[mini][i] - v[mink[k].first][mink[k].second] < 0)
					{
						if (max2 < abs(v[mini][i] - v[mink[k].first][mink[k].second]))
						{
							max2 = abs(v[mini][i] - v[mink[k].first][mink[k].second]);


						}
					}
				max = max + max2;
			}
			else {
				int max2 = 0;
				for (int k = 0; k < mink.size(); k++)
					if (v[mini][i] - v[mink[k].first][mink[k].second] > 0)
					{
						if (max2 < abs(v[mini][i] - v[mink[k].first][mink[k].second]))
						{
							max2 = abs(v[mini][i] - v[mink[k].first][mink[k].second]);


						}
					}
				max = max + max2;
			}
			if (minofmax > max)
				minofmax = max;
		}
		cout << minofmax+1 << "\n";

	}
	return 0;

}