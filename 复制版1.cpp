#include<bits/stdc++.h>
using namespace std;
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
ostream &operator<<(ostream &os , int128 num){
	if (num == 0) return os << "0";
	str s;
	while(num > 0){
		s.push_back('0' + num % 10);
		num /= 10;
	}
	reverse(s.begin() , s.end());
	return os << s;
}
ll read(){
	int f = 1; ll res = 0;
	char ch = getchar();
	while(!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		res = (res << 3) + (res << 1) + (ch - '0');
		ch = getchar();
	}
	return res * f;
}
#define int long long
void solve(){
	
}
signed main(){
	IOS
	int t = 1;
	cin >> t;
	while(t --) solve();
	return 0;
}
/**测试加注释 20250720*/
