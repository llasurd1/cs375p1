#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;

int main(int argc, char *argv[]) {
        string marketNames[100];
	int marketPrices[100];
	string setNames[100][100];
	int setPrices[100][100];
	int spending[100];
	int numCards[100];
	int set = 0;
	int cards = 0;
       
	fstream file1(argv[2], fstream::in);
	fstream file2(argv[4], fstream::in);
	ofstream output;
	output.open("output.txt");
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
			cards++;
		}
	file1.close();
	}

	set = 0;
	if(file2.is_open()){
			while(!file2.eof() && !file2.fail()) {
				int first = 0;
				int second = 0;
				file2 >> first;
				file2 >> second;
				numCards[set] = first;
				spending[set] = second;
				for(int i = 0; i<first; i++) {
					string setName;
					int setPrice;
					file2 >> setName;
					file2 >> setPrice;
					setNames[set][i] = setName;
					setPrices[set][i] = setPrice;
				}
				set++;
				
			}
		file2.close();
	}
	for(int i = 0; i<set-1; i++) {
	  chrono::steady_clock sc;
	  auto start = sc.now();
	  int maxProfit = 0;
	  vector<string> s;
	  vector<string> m;
	  int n = pow(2, numCards[i]);
	  for(int j = 0; j<n; j++) {
	    
	    int totalCost=0;
	    for(int k = 0; k<numCards[i]; k++) {
	      if((j&(1 << k))!=0) {
		totalCost+=setPrices[i][k];                                                                                                                           
		s.push_back(setNames[i][k]);
	      }	      
	    }
	    if(totalCost<=spending[i]){
	      int tempProfit = 0;
	      for(int r = 0; r<s.size(); r++)	{
		for(int t = 0; t<cards; t++) {
		  if(s[r]==marketNames[t]) {
		    tempProfit+=marketPrices[t];
		  }
		}
		
	      }
	      tempProfit-=totalCost;
	      if(tempProfit>maxProfit) {
		maxProfit = tempProfit;
		m = s;
		s.clear();
	      }
	    }
	    s.clear();
	  }
	  auto end = sc.now();
	  auto time_span = static_cast<chrono::duration<double>>(end-start);
	  output << "Size: " << numCards[i] << " Max Profit: " << maxProfit << " Num cards purchased: " << m.size() << " Time Taken :" << time_span.count()<< " seconds " << "\n"; 
	}
     
}
