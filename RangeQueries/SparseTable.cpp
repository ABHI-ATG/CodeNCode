const int N = 1e5 + 5;
const int K = 17;
int sp[N][K];
int lg[N];
void solve(vector<int> &v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		sp[i][0] = v[i];
	}
	for (int i = 2; i < N; i++)
	{
		lg[i] = lg[i / 2] + 1;
	}
	for (int j = 1; j < K; j++)
	{
		for (int i = 0; i + (1 << (j - 1)) < n; i++)
		{
			sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r)
{
	int ret = 0;
	int len = r - l + 1;
	int segment = lg[len];
	ret = min(sp[l][segment], sp[r - (1 << segment) + 1][segment]);
	return ret;
}

int main()
{

	vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
	solve(v);
	return 0;
}