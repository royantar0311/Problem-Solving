#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tolim 10000006
ll phi[tolim], n, p, caseno;
void computeTotient() {
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= tolim; i++)
		phi[i] = i - 1;

	for (int i = 2; i <= tolim; i++)
		for (int j = 2 * i; j <= tolim; j += i)
			phi[j] -= phi[i];
	for (int i = 1; i < tolim; i++) {phi[i] += phi[i - 1] ;}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	computeTotient();
	cin >> T;

	while (T--) {
		cin >> n >> p;
		cout << "Case " << ++caseno << ": ";
		if (phi[n] < p) {
        cout << -1 << endl;
        continue;
    }
		ll ind = lower_bound(phi, phi + n, p) - (phi);
		cout << n / ind << endl;
	}
}
