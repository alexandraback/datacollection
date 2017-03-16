#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// int get_corners(int R, int C, bool takezz) {
// 	if (R % 2 == 0 && C % 2 == 0) {
// 		return 2;
// 	} else if (R % 2 == 0 && C % 2 == 1) {
// 		return (C > 1 ? 2 : 1);
// 	} else if (R % 2 == 1 && C % 2 == 0) {
// 		return (R > 1 ? 2 : 1);
// 	} else if (R % 2 == 1 && C % 2 == 1) {
// 		if (R == 1 && C == 1)
// 			return takezz ? 0 : 1;
// 		else if (C == 1)
// 			return takezz ? 0 : 1;
// 		else if (R == 1)
// 			return takezz ? 0 : 1;
// 		else
// 			return takezz ? 0 : 4;
// 	}
// }

// int get_vertical_sides(int R, int C, bool takezz) {
// 	if (R % 2 == 0 && C % 2 == 0) {
// 		return R - 2;
// 	} else if (R % 2 == 0 && C % 2 == 1) {
// 		return C > 1 ? R - 2 : (R - 2) / 2;
// 	} else if (R % 2 == 1 && C % 2 == 0) {
// 		return (R > 1 ? R - 2 : 0)
// 	} else if (R % 2 == 1 && C % 2 == 1) {
// 		if (R == 1)
// 			return 0;
// 		else if (C == 1)
// 			return takezz ? (R - 2 + 1) / 2 : (R - 2) / 2;
// 		else
// 			return takezz ? R - 2 : (R - 3)
// 	}
// }

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

inline bool inside(int x, int y, int R, int C) {
	return 0 <= x && x < R &&
		0 <= y && y < C;
}

int get_neighbors(int x, int y, int R, int C) {
	int r = 0;
	for (int k = 0; k < 4; k++) {
		if (inside(x + dx[k], y + dy[k], R, C)) {
			r++;
		}
	}
	return r;
}

int solve(int R, int C, int N, bool takezz) {
	int parity = takezz ? 0 : 1;
	int result = 0;
	// cerr << "For R = " << R << " C = " << C << " N = " << N << " takezz = " << takezz << "\n";
	for (int x = 0; N && x < R; x++) {
		for (int y = 0; N && y < C; y++) {
			if ((x + y) % 2 == parity) {
				N--;
			}
		}
	}
	// cerr << "N decreased to " << N << " result " << result << "\n";
	vector <pair <int, int> > corners;
	if (0 % 2 != parity)
		corners.push_back(make_pair(0, 0));
	if ((C - 1) % 2 != parity)
		corners.push_back(make_pair(0, C - 1));
	if ((R - 1) % 2 != parity)
		corners.push_back(make_pair(R - 1, 0));
	if ((R - 1 + C - 1) % 2 != parity)
		corners.push_back(make_pair(R - 1, C - 1));
	sort(corners.begin(), corners.end());
	corners.erase(unique(corners.begin(), corners.end()), corners.end());
	if (N == 0)
		return result;
	for (auto p : corners) {
		result += get_neighbors(p.first, p.second, R, C);
		N--;
		if (N == 0)
			return result;
	}
	// cerr << "N decreased to " << N << " result " << result << "\n";
	vector <pair <int, int> > sides;
	for (int x = 1; N && x < R - 1; x++) {
		if (x % 2 != parity)
			sides.push_back(make_pair(x, 0));
		if ((x + C - 1) % 2 != parity)
			sides.push_back(make_pair(x, C - 1));
	}
	for (int y = 1; N && y < C - 1; y++) {
		if (y % 2 != parity)
			sides.push_back(make_pair(0, y));
		if ((y + R - 1) % 2 != parity)
			sides.push_back(make_pair(R - 1, y));
	}
	sort(sides.begin(), sides.end());
	sides.erase(unique(sides.begin(), sides.end()), sides.end());
	for (auto p : sides) {
		result += get_neighbors(p.first, p.second, R, C);
		//cerr << "Side " << p.first << " " << p.second << " neighbors " << get_neighbors(p.first, p.second, R, C) << "\n"; 
		N--;
		if (N == 0)
			return result;
	}
	// cerr << "N decreased to " << N << " result " << result << "\n";
	//int inner = (R - 2) * (C - 2) / 2;
	for (int x = 1; N && x < R - 1; x++) {
		for (int y = 1; N && y < C - 1; y++) {
			if ((x + y) % 2 != parity) {
				N--;
				result += 4;
			}
		}
	}
	// cerr << "N decreased to " << N << " result " << result << "\n";
	assert(N == 0);
	return result;
}

// int solve(int R, int C, int part1, int part2, int N) {
// 	if (N <= part1) {
// 		return 0;
// 	} else {
// 		int result = 0;
// 		N -= part1;
// 		if (part1 < part2) {
// 			int horizontal_corners = (C > 1 ? 2 : 1);
// 			int vertical_corners = (C > 1 ? 2 : 1);
// 			int corners = horizontal_corners * vertical_corners;
// 			int _ = min(corners, N);
// 			result += _ * ((R > 1 ? 1 : 0) + (C > 1 ? 1 : 0));
// 			N -= _;
// 			int sides = ((C - horizontal_corners) / 2) * (vertical_corners) +
// 				((R - vertical_corners) / 2) * (horizontal_corners);
// 			_ = min(sides, N);
// 			result += _ * 3;
// 			N -= _;
// 			int inside = ((R - vertical_corners) * (C - horizontal_corners) + 1) / 2;
// 			_ = min(inside, N);
// 			N -= _;
// 			result += _ * 4;
// 		} else if (part1 > part2) {
// 			int sides = ((C - horizontal_corners + 1) / 2) * (vertical_corners) +
// 				((R - vertical_corners + 1) / 2) * (horizontal_corners);
// 			int _ = min(sides, N);
// 			result += _ * 3;
// 			N -= _;
// 			int inside = ((R - vertical_corners) * (C - horizontal_corners)) / 2;
// 			_ = min(inside, N);
// 			N -= _;
// 			result += _ * 4;
// 		} else {
// 			int corners = (R > 1 ? 1 : 0) + (C > 1 ? 1 : 0);
// 		}
// 		return result;
// 	}
// }

int main() {
	int T, tn = 0, R, C, N;
	cin >> T;
	while (T --> 0) {
		cin >> R >> C >> N;
		// int part1 = (R * C) / 2;
		// int part2 = R * C - part1;
		cerr << "Computing #" << tn + 1 << "\n";
		int result = 0;
		result = min(
			solve(R, C, N, false),
			solve(R, C, N, true)
		);
		cout << "Case #" << (++tn) << ": " << result << "\n";
	}
	return 0;
}