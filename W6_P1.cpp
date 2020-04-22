#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	string s;
	string b;
	
	while (T--) {
		vector<int>v;
		vector<int>bb;
		cin >> s >> b;
		

		for (int i = 0; i < s.size(); i++)
			v.push_back(s[i]-'0');
		for (int i = 0; i < b.size(); i++)
			bb.push_back(b[i] - '0');
		int times = s.size() - b.size();
		int pointer = b.size();
		int left = 0;
		int A = 0, B = 0;
		
		for (int j = 0; j < b.size(); j++)
		{
			A += v[j] * pow(10, b.size() - j - 1);
			B += bb[j] * pow(10, b.size() - j - 1);

		}
		while(A>=B)
			A = A - B;
		left = A;
		for (int i = 0; i < times; i++)
		{
			A = left * 10 + v[pointer];
			while (A >= B)
				A = A - B;
			left = A;
			pointer++;
		}
		if (left == 0)
			cout << "1\n";
		else
			cout << "0\n";

	
	}
	return 0;
}
