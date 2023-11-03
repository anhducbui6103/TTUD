// bài toán đưa về đếm số xâu nhị phân độ dài n sao cho :
// - không chứa 2 số 0 liên tiếp nhau
// - các đoạn 1 liền nhau có độ dài >=k1 và <= k2

// bài toán con:
// dp(i) = Đếm số xâu nhị phân độ dài i thoả mãn yêu cầu
// nếu a[i] = 0 thì a[i-1] = 1
// nếu a[i] = 1 thì:
// xét j từ phải sang trái sao cho j là số đầu tiên để a[j] = 0 => k1 <= i-j <= k2 <=> i-k2 <= j <= i - k1;

// => quy về 2 bài toán dp(i,0): đếm số xâu nhị phân độ dài i kết thúc = 0 thoả mãn
// dp(i,1): đếm số xâu nhị phân độ dài i kết thúc = 1 thoả mãn

// => dp(i,0) = dp(i-1,1);
// dp(i,1) = res : for ( j = i-k2; j<= i - k1; j++) res += dp(j,0);
// dp(0,0) = 1
// dp(0,1) = 1

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
int n, k1, k2;
int mem[N][2];

int dp(int i, int work) // work = 1 : ngày làm việc, work = 0 : ngày nghỉ
{
    if (i == 0)
        return mem[i][work] = 1;
    if (mem[i][work] != 0)
        return mem[i][work];
    int res = 0;
    if (work == 0)
    {
        res = dp(i - 1, 1) % MOD;
    }
    else
    {
        for (int j = i - k2; j <= i - k1; j++)
            if (j >= 0)
                res = (res + dp(j, 0)) % MOD;
    }
    return mem[i][work] = res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(mem, 0, sizeof(mem));
    cin >> n >> k1 >> k2;
    cout << dp(n, 1) + dp(n, 0);
    return 0;
}