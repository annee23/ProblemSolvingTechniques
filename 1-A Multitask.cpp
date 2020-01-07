#include <iostream>
using namespace std;
//멀티태스크 성능측정 1-A
int main() {
	std::ios::sync_with_stdio(false);
	int T, N, a, b;
	int CPU = 0;
	int tempA, tempB, tB;
	int sumA = 0, sumB = 0;
	cin >> T;
	while(T--) {
		cin >> N;
		CPU = 0; sumA = 0, sumB = 0;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			if (i == 0)
			{
				CPU = a;
				tempA = 0; tempB = b; tB = b;
			}
			else {
				CPU += tB;
				tempA = CPU - a;
				tempB = tempA + b;
				tB = b;//이거옮기고 확인못함
			}
			sumA += tempA;
			sumB += tempB;
		}
		cout << sumA / N << " " << sumB / N << "\n";
	}
	return 0;
}