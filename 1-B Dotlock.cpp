#include <iostream>
#include<vector>
using namespace std;
//��Ƽ�½�ũ �������� 1-B
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, M, X, t;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<int> v;
		cin >> t; v.push_back(t);
		while (--N) {
			cin >> t;
			for (int i = 0; i < v.size(); i++)
				if (t > v[i])
				{
					v.insert(v.begin() + i, t);
					break;
				}
		}
		while (M--) {
			cin >> X;
			for (int i= v.size()-1;i>=0; i--) //���������ε� ���������ε� ������������ �ؾ� ����
				if (v[i] == X)
				{
					cout << v.size()-i << "\n"; 
					break;
				}
		}
		while (!v.empty())
			v.pop_back();
	}
	return 0;
}