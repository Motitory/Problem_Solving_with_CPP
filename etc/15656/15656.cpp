#include <iostream>
#include <algorithm>

using namespace std;

int a[10];
int num[10];
int c[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << num[a[i]];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}
int main(int argc, char* argn[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	go(0, n, m);
	return 0;
}