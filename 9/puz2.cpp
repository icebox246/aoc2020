//Project: puz1
#include <bits/stdc++.h>
using namespace std;

int n;
deque<long long> nums;
long long numeros[1005];

#define SIZE 25

int main() {
	ifstream inp("./in1");
	int totalC = 0;
	long long foundN = 0;
	while(inp.peek() != EOF) { 
		inp>>numeros[totalC];
		if(nums.size() == SIZE) {
			bool found = false;
			/* cout << numeross.size() << '\n'; */
			for(int i = 0; i < SIZE; i++) {
				for(int j =0; j < SIZE; j++) { 
					if(nums[i]==nums[j]) continue;
					if(nums[i]+nums[j] == numeros[totalC]) {
						found = true;
						cout << nums[i] << " + " << nums[j] << " = " << numeros[totalC] << '\n';
						break;
					}
				}
				if(found) break;
			}
			if(!found) {
				foundN = numeros[totalC];
				break;
			}
		}
		nums.push_back(numeros[totalC]);
		if(nums.size()>SIZE) nums.pop_front();
		totalC++;
	}

	int l=0, r=1;
	long long cs = numeros[0];
	while(l!=r) {
		while(cs > foundN) {
			cs -= numeros[l];
			l++;
		}	
		if(cs == foundN) {
			/* cout << l << " " << r; */
			break;
		}
		cs+=numeros[r];
		r++;	
	}

	long long cmin = 1e14, cmax = 0;

	for(int i = l; i < r; i++) {
		cmin = min(cmin, numeros[i]);
		cmax = max(cmax, numeros[i]);
	}

	cout << cmax + cmin << '\n';
}
