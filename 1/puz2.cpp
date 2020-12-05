// Project: puz2
#include <bits/stdc++.h>
using namespace std;

long cnt[2024];
vector<int> nums;

int main() {
	ifstream input("in1");
	int c = 1;
	while(input.peek() != EOF) {
		input>>c;
		nums.push_back(c);
	}
	input.close();

	for(auto a : nums) {
		for(auto b : nums) {
			if(&a==&b || a+b > 2020) continue;
			cnt[a+b] = long(a) * b;
		}
	}


	for(auto a : nums) {
		if(a <= 2020 && cnt[2020-a]) {
			cout << a * cnt[2020-a] << '\n';
			return 0;
		}
	}
}
