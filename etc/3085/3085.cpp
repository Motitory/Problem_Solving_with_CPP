#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<string> &a) {
	int n = a.size();
	int ans = 1;
	// 행으로 검사
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (a[i][j] == a[i][j - 1])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}

		// 열로 검사
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (a[j][i] == a[j - 1][i])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
	}
	return ans;
}

int main(int argc, char* argn[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// 오른쪽과 교환하여 체크
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a);
				if (ans < temp) ans = temp;
				swap(a[i][j + 1], a[i][j]);
			}
			// 아래쪽과 교환하여 체크
			if (i + 1 < n) {
				swap(a[i][j], a[i + 1][j]);
				int temp = check(a);
				if (ans < temp) ans = temp;
				swap(a[i][j], a[i + 1][j]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}