#pragma once
// =delete必须出现在函数第一次声明时
struct NoCopy 
{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete; // 阻止拷贝
	NoCopy &operator=(const NoCopy&) = delete; // 阻止赋值
	~NoCopy() = default; // 不能删除析构函数
};