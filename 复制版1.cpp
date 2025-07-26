#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll = long long;
using db = double;
using ull = unsigned long long;
#define endl "\n"
#define vec vector
#define int128 __int128
#define gcd __gcd
#define str string
#define unmap unordered_map
#define db double
#define unset unordered_set
#define int long long
#define pii pair<int , int>

ostream &operator<<(ostream &os, int128 num) {
	if (num == 0) return os << "0";
	str s;
	while (num > 0) {
		s.push_back(static_cast<char>(48 + num % 10));
		num /= 10;
	}
	ranges::reverse(s);
	return os << s;
}

signed main() {
	IOS

	return 0;
}
