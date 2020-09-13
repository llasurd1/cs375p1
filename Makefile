all: lasurdo_l_p1

p1: lasurdo_l_p1.cpp
	g++ -g lasurdo_l_p1.cpp -o lasurdo_l_p1

clean:
	rm -rf lasurdo_l_p1
