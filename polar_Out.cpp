#include "polar_atd.h"
using namespace std;
namespace simple_numbers {
	// ����� �������� ���������
	void polar::Out(ofstream& ofst) {
		ofst << "It is polar: r = " << r << ", fi = " << fi << endl;
	}
} // end simple_numbers namespace