#pragma once
// =delete��������ں�����һ������ʱ
struct NoCopy 
{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete; // ��ֹ����
	NoCopy &operator=(const NoCopy&) = delete; // ��ֹ��ֵ
	~NoCopy() = default; // ����ɾ����������
};