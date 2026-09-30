setpoly ln(const setpoly &x) {
	assert(x[0] == 1);
	setpoly y = {0};
	for (int i = 1; i < x.size(); i <<= 1) {
		setpoly z(x.begin(), x.begin() + i);
		setpoly u(x.begin() + i, x.begin() + (i << 1));
		z = convinv(z, u);
		y.insert(y.end(), z.begin(), z.end());
	}
	return y;
}