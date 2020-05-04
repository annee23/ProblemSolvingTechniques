#include<iostream>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, price, wrap;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<vector<int>> v;
		v.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> price >> wrap;
			v[i].push_back(price);
			v[i].push_back(wrap);
		}
		int sum = 0;
		int min = 1500;
		deque<int>deq;
		int pointer = -1;
		int count = 1;
		for (int i = N - 1; i >= 0;) {
			if (i == 0)
				deq.push_back(v[i][0]);
			else if (v[i - 1][0] > v[i][1] && v[i - 1][1] > v[i][1])
			{
				deq.push_back(v[i][1]);
				pointer = 1;
				count++;
				//i--;
			}
			else if (v[i][0] < v[i][1])		//마지막 오 왼 설정
			{
				deq.push_back(v[i][0]);
				pointer = 0;
				i--;
			}
			else
			{
				deq.push_back(v[i][1]);
				pointer = 1;
				i--;
			}
			while (1) {
				if (pointer == 1)
				{
					if (i == 0)
					{
						while (count--) {
							if (min > v[i + count][0])
								min = v[i + count][0];
						}
						/*if (min > v[i + count][0])
							min = v[i + count][0];*/
						deq.push_back(min);
						i--;
						break;
					}
					else if (v[i - 1][0] < v[i - 1][1])
					{
						if (i == 1)
						{
							deq.pop_back();
							deq.push_back(v[i - 1][0]);
							while (count--) {
								if (min > v[i + count][0])
									min = v[i + count][0];
							}
							/*if (min > v[i + count][0])
								min = v[i + count][0];*/
							deq.push_back(min);
							i -= 2;
							break;
						}

						pointer = 0;
						deq.push_back(v[i - 1][0]);
						i -= 2;
						break;

					}
					else
					{
						pointer = 1;
						count++;
						deq.push_back(v[i][1]);
						i--;
					}

				}
				else {
					i--;
					break;
				}
			}
		}
		while (deq.size())
		{
			sum += deq.front();
			deq.pop_front();
		}
		for (int i = 0; i < N; i++)
			sum += v[i][0];
		cout << sum << "\n";
	}
}