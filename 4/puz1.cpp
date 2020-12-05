// Project: puz1
#include <bits/stdc++.h>
using namespace std;

map<string, string> fields;
string hairColors[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

int C = 0;

bool validate() {
	int D = 0;
	for(auto &f : fields){
		if(f.second.size()) {
			if(f.first == "byr" && stoi(f.second)>=1920 && stoi(f.second)<=2002) D++;
			if(f.first == "iyr" && stoi(f.second)>=2010 && stoi(f.second)<=2020) D++;
			if(f.first == "eyr" && stoi(f.second)>=2020 && stoi(f.second)<=2030) D++;
			if(f.first == "hgt") {
				string unit = (f.second.substr(f.second.size()-2,2));
				if(unit == "cm") {
					int val = stoi(f.second.substr(0,f.second.size()-2));
					if(val>=150 && val <=193) D++;
				}
				if(unit == "in") {
					int val = stoi(f.second.substr(0,f.second.size()-2));
					if(val>=59 && val <=76) D++;
				}
			}
			if(f.first == "hcl") {
				if(f.second.size() == 7 && f.second[0] == '#') {
					int d = 0;
					for(int i = 1; i <= 7; i++) {
						char c = f.second[i];
						if((c>='0' && c <= '9') || (c>= 'a' && c <= 'f')) d++;
					}
					if (d==6) D++;
				}
			}
			if(f.first == "ecl") {
				for(auto c : hairColors) {
					if(c == f.second) {
						D++;
						break;
					}
				}	
			}
			if(f.first == "pid") {
				if(f.second.size() == 9) {
					int d= 0;
					for(int i = 0; i <9; i++) {
						if(f.second[i] > '0' && f.second[i] <='9') d++;
					}
					if (d==9) D++;
				}
			}
			if(f.first == "cid") D++;
		}
		f.second = "";
	}
	if(8==D) {
		C++;
		return true;
	}
	return false;
}

int main() {
	ifstream inp("in1");

	fields["byr"]="";
	fields["iyr"]="";
	fields["eyr"]="";
	fields["hgt"]="";
	fields["hcl"]="";
	fields["ecl"]="";
	fields["pid"]="";
	fields["cid"]="";


	while(inp.peek()!=EOF) {
		string line;
		getline(inp,line);
		if(line.size() < 3) {
			validate();
		} else {
			stringstream sline;
			sline << line;
			int fc = count(line.begin(),line.end(),' ') + 1;

			while(fc--) {
				string field;
				sline >> field;
				int end = field.find(':');
				string name = field.substr(0, end);
				string value = field.substr(end+1, field.size() - end);
				fields[name]=value;
			}
		}
	}
	validate();

	inp.close();

	cout << C;
}
