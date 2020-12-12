class dsu {
  public:
  vector<int> p, ra;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    ra.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (ra[x] > ra[y]) swap(x, y);
    p[y] = x;
    ra[x] += ra[x] == ra[y];
    return true;
};
