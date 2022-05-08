#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main()
{
	vector<long long> dp(100001);
	dp[0] = 1;
	long long num = 1;

	for (int i=1;i<=100000;i++)
		dp[i] = num = (num % MOD * i % MOD) % MOD;

	int q;
	cin>>q;

	while (q--)
	{
		int x;
		cin>>x;

		cout<<dp[x]<<"\n";
	}

	return 0;
}
