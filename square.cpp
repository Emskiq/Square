#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int a;
	cin >> a;

	int max = 0, counter = 0;
	vector<int> lines;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j < i; j++) {
			long x = i * i + j * j;
			long double len = sqrt(x);
			if (len - floor(len) == 0) {
				if (max < len) {
					max = len;
				}
				if (!count(lines.begin(), lines.end(), len)) {
					counter++;
					lines.push_back(len);
				}
			}
		}
	}

	cout << max << " " << counter;
}


