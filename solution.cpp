#include <iostream>
#include <vector>
#include <map>


std::vector<int>* nextGen(std::vector<int>& thisGen, int n) {
	n = n + 2;
	int sum = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			sum = (
				thisGen[(i - 1) * n + j - 1] +
				thisGen[(i - 1) * n + j] +
				thisGen[(i - 1) * n + j + 1] +
				thisGen[(i * n) + j - 1] +
				thisGen[(i * n) + j + 1] +
				thisGen[(i + 1) * n + j - 1] +
				thisGen[(i + 1) * n + j] +
				thisGen[(i + 1) * n + j + 1]
				);
			if (sum < 2) {
				thisGen[i * n + j] = 0;
			}
			else if (sum > 3) {
				thisGen[i * n + j] = 0;
			}
			else if (sum == 3) {
				thisGen[i * n + j] = 1;
			}
		}
	}
	return &thisGen;
}

void printBoard(std::vector<int>& thisGen, int n) {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			std::cout << thisGen[i * (n + 2) + j] << " ";
		}
		std::cout << std::endl;
	}
}

int findMotifA(std::vector<int>& thisGen, int n, std::vector<int>& motif, int q, int r) {
	int p = 0;
	int i = 0;
	while (p < (n + 1) * (n + 2)) {
		if (p < (n + 2)) {
			p = n + 3;
			i = 0;
		}
		else if (p % (n + 2) == 0) {
			p++;
			i = 0;
		}
		else if (p % (n + 2) == n + 1) {
			p++;
			i = 0;
		}

		else {
			int k = p;
			while (thisGen[p] == motif[i]) {
				//std::cout << i << " " << p << "\n";
				i++;
				if (i % q == ((q - r) % q)) {
					i += r;
					if (i == (q + 1) * (q - r - 1) + 1 + r) {
						std::cout << "Yin";
						return 1;
					}
					p += n + 3 - q + r;
				}
				else {
					p++;
				}
			}
			p = k + 1;
			i = 0;
		}
	}
	return 0;
}

int findMotifB(std::vector<int>& thisGen, int n, std::vector<int>& motif, int q, int r) {
	int p = 0;
	int i = 0;
	while (p < (n + 1) * (n + 2)) {
		if (p < (n + 2)) {
			p = n + 3;
			i = 0;
		}
		else if (p % (n + 2) == 0) {
			p++;
			i = 0;
		}
		else if (p % (n + 2) == n + 1) {
			p++;
			i = 0;
		}

		else {
			int k = p;
			while (thisGen[p] != motif[i]) {
				i++;
				if (i % q == ((q - r) % q)) {
					i += r;
					if (i == (q + 1) * (q - r - 1) + 1 + r) {
						std::cout << "Yang";
						return 1;
					}
					p += n + 3 - q + r;
				}
				else {
					p++;
				}
			}
			p = k + 1;
			i = 0;
		}
	}
	return 0;
}




int main() {
	int n;
	std::cin >> n;
	int bit;
	std::vector<int> board;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || i == n + 1) {
				board.push_back(0);
			}
			else if (j == 0 || j == n + 1) {
				board.push_back(0);
			}
			else {
				std::cin >> bit;
				board.push_back(bit);
			}
		}
	}
	int q;
	std::cin >> q;
	std::vector<int> motif;

	for (int i = 0; i < q * q; i++) {
		std::cin >> bit;
		motif.push_back(bit);
	}
	int r = 0;
	std::map <std::vector<int>, int> map;
	map[board]++;
	std::vector<int> dead(n * n + 4 * n + 4, 0);
	map[dead]++;
	auto copy = board;
	while (!(findMotifA(board, n, motif, q, r) | findMotifB(board, n, motif, q, r))) {
		board = *nextGen(board, n);
		map[board]++;
		if (map[board] > 1) {
			r++;
			board = copy;
		}
	}

	if (r) {
		std::cout << " " << r;
	}
	return 0;
}