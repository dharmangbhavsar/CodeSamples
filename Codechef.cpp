#include <bits/stdc++.h>
using namespace std;
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define INF 1000000009
typedef long long LL;
const int V = 601;
const int N = 201;

int cost[V][V], g[N][V], l[V], nodes, teams;
int start[N];
bool seen[V];

bool kuhn(int u, int thresh) {
  for (int v = 1; v <= nodes; ++v) {
    if (!seen[v] && g[u][v] <= thresh) {
      seen[v] = 1;
      if (l[v] == -1 || kuhn(l[v], thresh)) {
        l[v] = u;
        return true;
      }
    }
  }
  return false;
}

int maxMatch(int thresh) {
  int res = 0;
  fill(l + 1, l + nodes + 1, -1);
  for (int i = 1; i <= teams; ++i) {
    fill(seen + 1, seen + nodes + 1, false);
    res += kuhn(i, thresh);
  }
  return res;
}

int bsearch(int L, int R, int K) {
  int mid;
  while (R - L > 1) {
    mid = (L + R) / 2;
    (maxMatch(mid) >= K ? R : L) = mid;
  }
  return R;
}



int main() {
  int v, e, n, k, u, t, a, b;
  scanf("%d %d %d %d", &v, &e, &n, &k);
  nodes = v;
  teams = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", start + i);
  }
  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      cost[i][j] = 1e9;
    }
    cost[i][i] = 0;
  }
  while (e--) {
    scanf("%d %d %d", &a, &b, &t);
    cost[b][a] = cost[a][b] = min(cost[a][b], t);
  }
  for (int w = 1; w <= v; w++) {
    for (int i = 1; i <= v; ++i) {
      for (int j = 1; j <= v; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][w] + cost[w][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= v; ++j) {
      g[i][j] = cost[start[i]][j];
    }
  }
  int maxAns = 1731311 + 1;
  int res = bsearch(-1, maxAns, k);
  if (res >= maxAns) res = -1;
  printf("%d", res);
  return 0;
}