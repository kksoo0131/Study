#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoiTower(int num, int from, int by, int to) {
	// 3가지 과정으로 분리할 수 있다.
	// 1. N-1 개를 치운다
	// 2. N번쨰를 원하는곳에 놓는다
	// 3. N-1개를 N위에 쌓는다.

	// 1은 그냥 옮겨준다.
	if (num == 1)
		cout << from << " " << to << '\n';
	else {
		// N-1개를 from -> by로 옮긴다.
		hanoiTower(num - 1, from, to, by);
		// N번을 to로 옮긴다.
		cout << from << " " << to << '\n';
		// N-1개를 by -> to로 옮긴다.
		hanoiTower(num - 1, by, from, to);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;

	// 2의 n제곱 -1이 원판의 개수
	// 2의 100승을 출력해야하므로 string으로 바꾸어서 계산
	string answer = to_string(pow(2, N));
	int x = answer.find('.');
	answer = answer.substr(0, x);
	answer[answer.length() - 1] -= 1;

	cout << answer << '\n';
    
    if (N > 20) {
		return 0;
	}

	hanoiTower(N, 1, 2, 3);

}