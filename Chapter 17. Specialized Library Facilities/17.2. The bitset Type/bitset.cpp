#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main() {
	/*初始化*/
	bitset<13> bitvec1(0xbeef); // 1_1110_1110_1111
	bitset<20> bitvec2(0xbeef); // 0000_1011_1110_1110_1111
	bitset<128> bitvec3(~0ULL); // 0x00000000000000001111111111111111
	
	bitset<32> bitvec4("1100"); // 0x1100
	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4);
	bitset<32> bitvec6(str, str.size() - 4);
	cout << bitvec5 << endl;
	cout << bitvec6 << endl;

	/*操作*/
	bitset<32> bitvec(1U);
	bool is_set = bitvec.any(); // true
	bool is_not_set = bitvec.none(); // false
	bool all_set = bitvec.all(); // false
	size_t onBits = bitvec.count(); // 1
	size_t sz = bitvec.size(); // 32
	bitvec.flip(); // 翻转所有位
	bitvec.reset(); // 全部复位
	bitvec.set(); // 全部置位

	bitvec.flip(0);
	bitvec.set(bitvec.size() - 1);
	bitvec.set(0, 0);
	bitvec.reset(2);
	bitvec.test(0);

	bitvec[0] = 0;
	bitvec[31] = bitvec[0];
	bitvec[0].flip();
	~bitvec[0];
	bool b = bitvec[0];

	unsigned long ulong = bitvec3.to_ulong();
	cout << "ulong = " << ulong << endl;
	bool status;
	unsigned long quizA = 0;
	quizA |= 1UL << 27;
	status = quizA & (1UL << 27);
	quizA &= ~(1UL << 27);

	bitset<30> quizB;
	quizB.set(27);
	status = quizB[27];
	quizB.reset(27);
}