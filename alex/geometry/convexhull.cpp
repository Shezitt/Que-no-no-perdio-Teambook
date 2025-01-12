struct pt {
	int x, y; 
};
int orientation(pt &a, pt &b, pt &c) {
	int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
	if (v<0) return -1;
	return v? 1: 0;
}
int cw(pt &a, pt &b, pt &c) {
	int o = orientation(a, b, c); 
	return o<0;
}
int collinear(pt &a, pt &b, pt &c) {return !orientation(a, b, c);}
void convexhull(vector<pt> &v, int inclu) {
	pt p0 = *min_element(v.begin(), v.end(), [](pt a, pt b){
			return make_pair(a.y, a.x)<make_pair(b.y, b.x);
			});
	sort(v.begin(), v.end(), [&p0](pt &a, pt &b){
				int o = orientation(p0, a, b); 
				int x = p0.x-a.x, y = p0.y-a.y; 
				int w = p0.x-b.x, z = p0.y-b.y;
				if (!o) return x*x+y*y<w*w+z*z;
				return o<0;
			});
	vector<pt> st; 
	for (int i= 0; i<v.size(); i++) {
		while (st.size()>1 && !cw(st[st.size()-2], st.back(), v[i])) st.pop_back();
		st.push_back(v[i]);
	}
	v = st;
	// devuelve los puntos sobre el mismo vector, en lado de reloj;
}