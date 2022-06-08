all:
	c++ -O3 -Wall -shared -std=c++11 -fPIC \
		-I /usr/include/python3.10 \
		-o example.so \
		example.cpp

clean:
	rm *.so