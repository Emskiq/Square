#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void first_version();
void second_version();

int main()
{
	second_version();
}

void second_version() {
	int a;
	cin >> a;

	int max = 0, counter = 0;
	vector<int> lines;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			long x = i*i+j*j;
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

void first_version() {
	int a;
	cin >> a;

	int max = 0, counter = 0;
	vector<int> lines;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k <= a; k++) {
				if (k != i) {
					for (int l = 0; l < k; l++) {
						if (l != j) {
							long x = (abs(i - k) * abs(i - k)) + (abs(j - l) * abs(j - l));
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
				}
			}
		}
	}

	cout << max << " " << counter;
}
