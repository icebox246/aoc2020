// Project: puz1
#include <bits/stdc++.h>
using namespace std;

bool cnt[2024];

int main() {
	ifstream input("in1");
	int c = 1;
	while(input.peek() != EOF) {
		input>>c;
		if(c>2020) continue;
		cnt[c]=1;
		if(cnt[2020-c]) {
			cout << c * (2020 - c);
			return 0;
		}
	}
	input.close();
}
