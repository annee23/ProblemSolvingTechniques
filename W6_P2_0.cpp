#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T; cin >> T;
	int M, N;
	while (T--) {
		cin >> M >> N;
		int t, sum = 0;
		for(int j=0;j<M;j++) {
			vector<int>v;
			for (int i = 0; i < N; i++)
			{
				cin >> t;
				v.push_back(t);
			}
			cin >> sum;
			int plus=0, multi=1;
			for (int i = 0; i < N; i++)
			{
				plus += v[i];
				multi *= v[i];
			}
			if (multi>plus?(multi<sum||plus>sum):(multi>sum||plus<sum))
				cout << 0;
			else if (sum == plus || sum == multi)
				cout << 1;
			else
				cout << 1;

			cout << " ";
		}
		cout << "\n";
	}
}
//2
//5 4 
//6 4 2 9 42
//1 3 2 4 10
//1 3 2 3 48
//2 4 6 8 384
//1 2 8 2 2356
//3 2 
//1 1 2
//3 8 95
//2 9 18
