struct Set{
	int l;
	long long sum = 0;
	multiset<ll> S, T;
	void add(int x) {
		if (sz(S) < l) {
			S.insert(x);
			sum += x;
		} else if (x > *S.begin()) {
			S.insert(x);
			sum += x;
			T.insert(*S.begin());
			sum -= *S.begin();
			S.erase(S.begin());
		} else {
			T.insert(x);
		}
	}

	void del(int x) {
		if (sz(T) == 0 || x > *T.rbegin()) {
			sum -= x;
			S.erase(S.find(x));
			if (!T.empty() && sz(S) < l) {
				S.insert(*T.rbegin());
				sum += *T.rbegin();
				T.erase(--T.end());
			}
		} else {
			T.erase(T.find(x));
		}
	}
};
