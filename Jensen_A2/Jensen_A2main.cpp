#include "Jensen_A2.h"

using namespace std;

int main() {

	cout << endl << endl;

	if (!DEBUG_MODE) {
		
		// ===================== Default Constructor =============================

		decimal dn, dn2, dn3;
		binary bn, bn2, bn3;
		hexadecimal hn, hn2, hn3;


		// ===================== Input (cin (istream) with operator>>) ===========

		cout << "Inputting a decimal (dn): " << endl;
		cout << "[Before] dn: " << dn << endl;
		cin >> dn;
		cout << "[After] dn: " << dn << endl;
		cout << endl;

		cout << "Inputting a binary (bn): " << endl;
		cout << "[Before] bn: " << bn << endl;
		cin >> bn;
		cout << "[After] bn: " << bn << endl;
		cout << endl;

		cout << "Inputting a hexadecimal (hn): " << endl;
		cout << "[Before] hn: " << hn << endl;
		cin >> hn;
		cout << "[After] hn: " << hn << endl;
		cout << endl;

		// ===================== Assignment (operator=) ==========================

		cout << "Assigning a binary (bn) into a decimal (dn2): " << endl;
		cout << "[Before] bn: " << bn << " dn2: " << dn2 << endl;
		dn2 = bn;
		cout << "[After] dn2: " << dn2 << endl;
		cout << endl;

		cout << "Assigning a hexadecimal (hn) into a decimal (dn3): " << endl;
		cout << "[Before] hn: " << hn << " dn3: " << dn3 << endl;
		dn3 = hn;
		cout << "[After] dn3: " << dn3 << endl;
		cout << endl;

		cout << "Assigning a decimal (dn) into a binary (bn2): " << endl;
		cout << "[Before] dn: " << dn << " bn2: " << bn2 << endl;
		bn2 = dn;
		cout << "[After] bn2: " << bn2 << endl;
		cout << endl;

		cout << "Assigning a hexadecimal (hn) into a binary (bn3): " << endl;
		cout << "[Before] hn: " << hn << " bn3: " << bn3 << endl;
		bn3 = hn;
		cout << "[After] bn3: " << bn3 << endl;
		cout << endl;

		cout << "Assigning a decimal (dn) into a hexadecimal (hn2): " << endl;
		cout << "[Before] dn: " << dn << " hn2: " << hn2 << endl;
		hn2 = dn;
		cout << "[After] hn2: " << hn2 << endl;
		cout << endl;

		cout << "Assigning a binary (bn) into a hexadecimal (hn3): " << endl;
		cout << "[Before] bn: " << bn << " hn3: " << hn3 << endl;
		hn3 = bn;
		cout << "[After] hn3: " << hn3 << endl;
		cout << endl;

		// ===================== Overwrite Assignment (operator=) ================

		cout << "Assigning a binary (bn) into a decimal with preexisting values (dn2): " << endl;
		cout << "[Before] bn: " << bn << " dn2: " << dn2 << endl;
		dn2 = bn;
		cout << "[After] dn2: " << dn2 << endl;
		cout << endl;

		cout << "Assigning a binary (bn) into a binary with preexisting values (bn2): " << endl;
		cout << "[Before] bn: " << bn << " bn2: " << bn2 << endl;
		bn2 = bn;
		cout << "[After] bn2: " << bn2 << endl;
		cout << endl;

		cout << "Assigning a binary (bn) into a hexadecimal with preexisting values (hn2): " << endl;
		cout << "[Before] bn: " << bn << " hn2: " << hn2 << endl;
		hn2 = bn;
		cout << "[After] hn2: " << hn2 << endl;
		cout << endl;

		cout << "Should all be the same value (decimal - binary - hexadecimal): "  << endl;
		cout << dn2 << " - " << bn2 << " - " << hn2 << endl;
		cout << endl;

		// ===================== Copy Constructors (parameterized) ===============

		cout << "Copy constructoring a binary (bn) into a decimal (dn4): " << endl;
		cout << "[Before] bn: " << bn << " dn4: UNDECLARED" << endl;
		decimal dn4(bn);
		cout << "[After] dn4: " << dn4 << endl;
		cout << endl;

		cout << "Copy constructoring a hexadecimal (hn) into a decimal (dn5): " << endl;
		cout << "[Before] hn: " << hn << " dn5: UNDECLARED" << endl;
		decimal dn5(hn);
		cout << "[After] dn5: " << dn5 << endl;
		cout << endl;

		cout << "Copy constructoring a decimal (dn) into a binary (bn4): " << endl;
		cout << "[Before] dn: " << dn << " bn4: UNDECLARED" << endl;
		binary bn4(dn);
		cout << "[After] bn4: " << bn4 << endl;
		cout << endl;

		cout << "Copy constructoring a hexadecimal (hn) into a binary (bn5): " << endl;
		cout << "[Before] hn: " << hn << " bn5: UNDECLARED" << endl;
		binary bn5(hn);
		cout << "[After] bn5: " << bn5 << endl;
		cout << endl;

		cout << "Copy constructoring a binary (bn) into a hexadecimal (hn4): " << endl;
		cout << "[Before] bn: " << bn << " hn4: UNDECLARED" << endl;
		hexadecimal hn4(bn);
		cout << "[After] hn4: " << hn4 << endl;
		cout << endl;

		cout << "Copy constructoring a decimal (dn) into a hexadecimal (hn5): " << endl;
		cout << "[Before] dn: " << dn << " hn5: UNDECLARED" << endl;
		hexadecimal hn5(dn);
		cout << "[After] hn5: " << hn5 << endl;
		cout << endl;

		// ===================== Final tests =====================================

		cout << "Testing whether conversions actually worked (should be all 1's): ";
		cout << endl;

		cout << dn.test();
		cout << dn2.test();
		cout << dn3.test();
		cout << dn4.test();
		cout << dn5.test();
		cout << endl;

		cout << bn.test();
		cout << bn2.test();
		cout << bn3.test();
		cout << bn4.test();
		cout << bn5.test();
		cout << endl;

		cout << hn.test();
		cout << hn2.test();
		cout << hn3.test();
		cout << hn4.test();
		cout << hn5.test();
		cout << endl;
	}
	else {
		// Testing environment

	}

	cout << endl;

	return 0;
}