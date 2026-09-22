setpoly ln(const setpoly &x) {
	assert(x[0] == 1);
	setpoly y = {0};
	for (int i = 0, j = 1; j < x.size(); i++, j <<= 1) {
		setpoly z(x.begin(), x.begin() + j);
		setpoly u(x.begin() + j, x.begin() + (j << 1));
		z = convinv(z, u);
		y.insert(y.end(), z.begin(), z.end());
	}
	return y;
}