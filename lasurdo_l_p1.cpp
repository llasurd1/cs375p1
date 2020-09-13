//./lasurdo_p1 sample_1.txt 010101010
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string marketNames[500]
	int marketPrices[500];
	string setNames[500][500]
	int setPrices[500][500];
	int spending[500];
	int set = 0;

	fstream file1(argv[1], fstream::in);
	fstream file2(argv[3], fstream::in);

	if(file1.is_open()){
		int first;
		file1 >> first;
		while(!file1.eof() && !file1.fail()) {
			string marketName;
			int marketPrice;
			file1 >> marketName;
			file1 >> marketPrice;
			marketNames[set] = marketName;
			marketPrices[set] = marketPrice;
			set++;
		}
	file1.close();
	}

	set = 0;
	if(file2.is_open()){
			while(!file2.eof() && !file2.fail()) {
				int first;
				int second
				file2 >> first;
				file2 >> second;
				spending[set] = second;
				for(int i = 0; i< first; i++) {
					string setName;
					int setPrice;
					file1 >> setName;
					file1 >> setPrice;
					setNames[set][i] = marketName;
					setPrices[set][i] = marketPrice;
				}
				set++;
			}
		file.close();
	}



}
