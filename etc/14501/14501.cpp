#include <iostream>

using namespace std;

const int inf = -100000000;
int t[21], p[21], n, ans = 0;

void go(int day, int sum) {
	if (day == n + 1) {
		if (ans < sum) ans = sum;
		return;
	}
	if (day > n + 1)
		return;
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}

int main(int argc, char* argn[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	
	go(1, 0);

	cout << ans << '\n';

	return 0;
}