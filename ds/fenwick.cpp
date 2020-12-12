class Fenwick {
	public:
	
	Fenwick(int _n);
	long long get(int k);
	void add(int k, int val);
		
	private:
	
	int n;
	vector<long long> tree;
};
 
Fenwick::Fenwick(int _n) {
	this->n = _n + 1;
	tree.resize(this->n);
}
 
long long Fenwick::get(int k) {
	long long sum = 0;
	for (++k; k; k -= k & -k)
		sum += tree[k];
	return sum;
}
 
void Fenwick::add(int k, int val) {
	for (++k; k < n; k += k & -k)
		tree[k] += val;
	return;
}
