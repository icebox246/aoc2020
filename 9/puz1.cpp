//Project: puz1
#include <bits/stdc++.h>
using namespace std;

int n;
deque<long long> nums;

#define SIZE 25

int main() {
	ifstream inp("./in1");
	while(inp.peek() != EOF) { 
		long long  num;
		inp>>num;
		if(nums.size() == SIZE) {
			bool found = false;
			/* cout << nums.size() << '\n'; */
			for(int i = 0; i < SIZE; i++) {
				for(int j =0; j < SIZE; j++) { 
					if(nums[i]==nums[j]) continue;
					if(nums[i]+nums[j] == num) {
						found = true;
						cout << nums[i] << " + " << nums[j] << " = " << num << '\n';
						break;
					}
				}
				if(found) break;
			}
			if(!found) {
				cout << num << '\n';
				return 0;
			}
		}
		nums.push_back(num);
		if(nums.size()>SIZE) nums.pop_front();
	}
}
