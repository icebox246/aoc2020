// Project: puz2
#include <bits/stdc++.h>
using namespace std;


int main() {
	ifstream inp("in1");

	int C = 0;

	while(inp.peek() != EOF) {
		string line;
		getline(inp,line);

		int end = line.find('-');
		int mi = stoi(line.substr(0,end));
		line.erase(0,end +1);
		end = line.find(' ');
		int mx = stoi(line.substr(0,end));
		line.erase(0,end +1);
		char q = line[0];
		line.erase(0,2);
		C+= ((line[mi]==q) != (line[mx]==q));
	}

	cout << C;

	inp.close();
}
