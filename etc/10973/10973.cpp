#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argn[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	} else cout << "-1";

	cout << '\n';

	return 0;
		
}