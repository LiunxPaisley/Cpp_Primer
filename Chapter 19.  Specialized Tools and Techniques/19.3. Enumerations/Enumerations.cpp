#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Tokens {INLINE = 128, VIRTUAL = 129};
void ff(Tokens);
void ff(int);
void newf(unsigned char);
void newf(int);

int main()
{
	// ���޶��������ö������
	enum color { red, yellow, green };
	//enum stoplight { red, yellow, green };
	// �޶����������ö�����ͣ�ö�ٳ�Ա������
	enum class peppers { red, yellow, green };

	color eyes = green;
	//peppers p = green;
	color hair = color::red; // ��ʽ����ö�ٳ�Ա
	peppers p2 = peppers::red; // ���ʳ�Ա

	// ָ��enum�Ĵ�С
	enum class intTypes
	{
		charTyp = 8, shortTyp = 16, intTyp = 16, 
		longTyp = 32, long_longTyp = 64
	};
	constexpr intTypes charbits = intTypes::charTyp;
	int i = color::red;
	// int j = peppers::red; // �޶��������ö�����Ͳ�����ʽת��

	// ö�����͵�ǰ������
	enum intValues : unsigned long long;// ���޶�������ģ�����ָ����Ա����
	enum class open_modes;//�޶��������ö�����Ϳ���ʹ��Ĭ�ϳ�Ա����int

	// �β�ƥ���ö������
	Tokens curTok = INLINE;
	ff(128);
	ff(INLINE);
	ff(curTok);
	unsigned char uc = VIRTUAL;
	newf(VIRTUAL);
	newf(uc);
	return 0;
}