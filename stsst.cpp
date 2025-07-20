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
const int N = 1e4 + 5 , M = 1 << 10 , mod = 1e6; // 增大M的值以容纳更多状态
int f[N][M] , idx;
int r[10] , n , m , c;
int s[M] , k , sum;
bool check(int x , int y){
	for (int i = 1 ; i <= m ; i++){
		if ((x % 3) == (y % 3)) return false;
		x /= 3 , y /= 3;
	}
	return true;
}
bool judge(int x){
	int la = -1;
	for (int i = 1 ; i <= m ; i++){
		if (x % 3 == la) return false;
		la = x % 3;
		x /= 3;
	}
	return true;
}
signed main(){
	IOS
	cin >> n >> m >> c;
	
	// 初始化r数组为3的幂
	r[0] = 1;
	for (int i = 1; i <= m; i++) {
		r[i] = r[i-1] * 3;
	}
	
	for (int i = 1 , t ; i <= m ; i++){
		cin >> t;
		sum = sum * 3 + (t - 1);
	}
	if (!judge(sum)){
		cout << 0;
		return 0;
	}
	
	// 生成所有合法状态
	k = 0;
	for (int i = 0 ; i < r[m] ; i++){ // 修正：枚举到3^m-1
		if (judge(i)){
			s[++k] = i;
			if (i == sum) idx = k;
		}
	}
	
	if (c == 1)
		f[1][idx] = 1;
	else
		for (int i = 1 ; i <= k ; i++)
			f[1][i] = 1;
	
	for (int i = 2 ; i <= n ; i++){
		if (i == c){
			for (int y = 1 ; y <= k ; y++){
				if (check(s[idx] , s[y])){
					f[i][idx] = (f[i][idx] + f[i - 1][y]) % mod;
				}
			}
		}else{
			for (int x = 1 ; x <= k ; x++){
				if (i - 1 == c){
					if (check(s[x] , s[idx]))
						f[i][x] = (f[i][x] + f[i - 1][idx]) % mod;
				}else{
					for (int y = 1 ; y <= k ; y++){
						if (check(s[x] , s[y])){
							f[i][x] = (f[i][x] + f[i - 1][y]) % mod;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= k ; i++)
		ans = (ans + f[n][i]) % mod;
	cout << ans;
	return 0;
}
