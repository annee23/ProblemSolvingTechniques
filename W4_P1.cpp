#include<iostream>
#include<vector>
using namespace std;
bool func(int i, vector<int>v, vector<int>pair) {
	int tmp;
	tmp = v[i];
	while (tmp != i)
	{
		if (tmp == v[tmp])
			return 0;
		else
			tmp = v[tmp];
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		int N, t; cin >> N;
		vector<int>choose;
		choose.push_back(-1);
		vector<int>pair;
		pair.push_back(-1);
		pair.resize(N+1);
		for (int i = 0; i < N; i++) {
			cin >> t;
			choose.push_back(t);
		}
		for (int i = 1; i < N + 1; i++) {
			if (choose[i] == i)
			{
				pair[i] = 2;
			}
			else
				pair[i]=func(i, choose, pair);
		}
		int count = 0;
		for (int i = 1; i < N + 1; i++) {
			if (pair[i]==0)
				count++;
		}
		cout << count << "\n";
	}
}