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
namespace DBG{
	template <class T>
	void _dbg(const char *f , T t) {cerr << f << '=' << t << endl;}
	template <class A , class... B>
	void _dbg(const char *f , A a , B... b){
		while(*f != ',') cerr << *f ++;
		cerr << '=' << a << ',';
		_dbg(f + 1 , b...);
	}
	template <class T>
	ostream& operator << (ostream& os , const vec<T> &v){
		os << "[ ";
		for (const auto &x : v) os << x << ", ";
		os << "] ";
		return os;
	}
#define dbg(...) _dbg(#__VA_ARGS__ , __VA_ARGS__)
}
using namespace DBG;
const int maxn = 1e5 + 10;
int tr[maxn];
int lowbit(int x){return x & (-x);}
void update(int x , int d){
	while(x < maxn){
		tr[x] += d;
		x += lowbit(x);
	}
}
int query(int x){
	int sum = 0;
	while(x > 0){
		sum += tr[x];
		x -= lowbit(x);
	}
	return sum;
}
void solve(){
	int n; cin >> n;
	vec<int> a(n) , sa(n);
	for (int &x : a) cin >> x;
	sa = a;
	sort(sa.begin() , sa.end());
	sa.erase(unique(sa.begin() , sa.end()) , sa.end());
	int ma = 0;
	for (int i = 0 ; i < n ; i++){
		int id = lower_bound(sa.begin() , sa.end() , a[i]) - sa.begin() + 1;
		int res = query(maxn - 1) - query(id);
		ma = max(ma , res);
		update(id , 1);
	}
	cout << ma + 1 << endl;
}
int main(){
	IOS
	int t = 1; //cin >> t;
	while(t --) solve();
	return 0;
}
