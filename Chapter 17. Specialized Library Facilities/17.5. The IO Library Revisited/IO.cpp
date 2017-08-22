#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	cout << "alpha bool values: " << boolalpha << true << " " << false << endl;
	cout << noboolalpha << true << endl;
	cout << endl;
	/*����*/
	cout << uppercase <<showbase;
	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "octal: " << oct << 20 << " " << 1024 << endl;
	cout << "hex: " << hex << 20 << " " << 1024 << endl;
	cout << "decimal: " << dec << 20 << " " << 1024 << endl;
	cout << nouppercase <<noshowbase;
	cout << endl;
	/*��ӡ����*/
	cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
	cout.precision(2);
	cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
	cout << setprecision(3);
	cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
	cout.precision(6);
	cout << endl;
	/*ָ��������������*/
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";
	/*��ӡС����*/
	cout << 10.0 << endl;
	cout << showpoint << 10.0 << noshowpoint << endl;
	cout << endl;

	/*�������*/
	int i = -16;
	double d = 3.14159;
	cout << "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << left
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< right;
	cout << right
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << internal
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	cout << setfill('#')
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< setfill(' ');

	/*���������ʽ*/
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		cout << ch;
	}
	cin >> skipws;

}