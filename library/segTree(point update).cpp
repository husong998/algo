void build_tree(int v, int tl, int tr) {
  if (tl == tr) t[v] = a[tl];
  else {
    int m = (tl + tr) / 2;
    build_tree(v * 2, tl, m);
    build_tree(v * 2 + 1, m + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return INF;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) /  2;
  return min(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) t[v] = new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v * 2, tl, tm, pos, new_val);
    else update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
