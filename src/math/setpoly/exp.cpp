setpoly exp(const setpoly &x) {
	assert(!x[0]);
	setpoly y = {1};
	for (int i = 1; i < x.size(); i <<= 1) {
		setpoly z(x.begin() + i, x.begin() + (i << 1));
		z = conv(z, y);
		y.insert(y.end(), z.begin(), z.end());
	}
	return y;
}