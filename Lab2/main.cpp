#include <iostream>

using namespace std;

void swap(short& one, short& two) {
	short placeholder = one;
	one = two;
	two = placeholder;
}

void Cswap(short* one, short* two) {
	short placeholder = *one;
	*one = *two;
	*two = placeholder;
}

int main() {
	char a;
	short b;
	float c;
	int d;
	double e;
	long f;


	cout << "a: " << sizeof(a) << endl;
	cout << "b: " << sizeof(b) << endl;
	cout << "c: " << sizeof(c) << endl;
	cout << "d: " << sizeof(d) << endl;
	cout << "e: " << sizeof(e) << endl;
	cout << "f: " << sizeof(f) << endl;

	short g[10] = {34, -7, 4, 3, 88, 19, 21, -7, 9, 0};

	cout << "g: " << sizeof(g) << endl;

	cout << "g2: " << g << endl;
	cout << "&g[0]: " << &g[0] << endl;
	cout << "g[0]: " << g[0] << endl;

	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << "&g[" << i << "]: " << &g[i] << endl;
	}

	cout << endl;

	for (short* h = g; h < &g[10]; h++) {
		cout << "h: " << h << " - value: " << *h << endl;
	}

	cout << endl;

	short placeholder;
	for (short* front = g, *back = (front + 9); front < back; front++, back--) {
		cout << front << " - " << back << endl;
		placeholder = *back;
		*back = *front;
		*front = placeholder;
	}

	cout << endl;

	for (short* h = g; h < &g[10]; h++) {
		cout << "h: " << h << " - value: " << *h << endl;
	}

	cout << endl;

	short i      = 43;
	short *ip    = &i;
	short V[3]   = {3, 14, 5};
	short *vp    = V;
	short *ap    = 0;

	cout << "*ip:   " << *ip   << "                *(vp+1): "  << *(vp + 1) << endl;
	cout << "&V[4]: " << &V[4] << "    *vp+1:   "              << *vp + 1 << endl;
	cout << "vp[2]: " << vp[2] << "                 vp+3:    " << vp + 3 << endl;
	cout << "*vp:   " << *vp   << "    "                       << endl; //<< *ap << endl; - SEG FAULT

	cout << endl;

	short o = 4;
	short t = 5;

	cout << "o: " << o << endl;
	cout << "t: " << t << endl;
	swap(o, t);
	cout << "o: " << o << endl;
	cout << "t: " << t << endl;

	cout << endl;

	cout << "o: " << o << endl;
	cout << "t: " << t << endl;
	Cswap(&o, &t);
	cout << "o: " << o << endl;
	cout << "t: " << t << endl;

	cout << endl;

	
}