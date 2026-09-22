setpoly exp(const setpoly &x) {
	assert(!x[0]);
	setpoly y = {1};
	for (int i = 0, j = 1; j < x.size(); i++, j <<= 1) {
		setpoly z(x.begin() + j, x.begin() + (j << 1));
		z = conv(z, y);
		y.insert(y.end(), z.begin(), z.end());
	}
	return y;
}