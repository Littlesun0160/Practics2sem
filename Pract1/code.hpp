#pragma once
#include <string>
#include <iostream>
#include <string>

class Code
{
private:
	std::string m_Text;
	std::string m_Words[30];
	std::string m_Cipher[30];
	int m_NumFib[30];
	int m_WordsQuantity;
public:
	Code(const std::string& Text)
	{
		m_Text = Text;
	}
	~Code() {}

	void Encode();
	void Decode(int Cipher[30]);
	bool Test(int Cipher[30]);
	int getCount() const
	{
		return m_WordsQuantity;
	}
};