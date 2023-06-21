#include "testlib.h"
#include <iostream>

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int q = atoi(argv[2]);
	std::cout << n << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << rnd.next(1) << " ";
		}
		std::cout << "\b\n";
	}
	std::cout << q << std::endl;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < q; j++) {
			std::cout << rnd.next(1) << " ";
		}
		std::cout << "\b\n";
	}
	return 0;
}