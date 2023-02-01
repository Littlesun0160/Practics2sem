#include "code.hpp"
#include <iostream>
#include <string>

void Code::Encode()
{
	int n = 0;							//Разбиение строки на массив слов
	while (m_Text.find(" ") != (-1))
	{
		int k = m_Text.find(" ");
		m_Words[n] = m_Text;
		m_Words[n].erase(k);
		m_Text.erase(0, k+1);
		n += 1;
	}
	m_Words[n] = m_Text;
	m_WordsQuantity = n + 1;			//Количество слов в строке
	if (m_WordsQuantity > 30)
	{
		std::cout << "Error.Too many words per line" << "\n";
		
	}

	m_NumFib[0] = 1;						//Создание массива из последовательности Фиббоначи
	m_NumFib[1] = 2;
	for (int i = 2; i < 30; i++)
	{
		m_NumFib[i] = m_NumFib[i - 1] + m_NumFib[i - 2];
	}
	for (int i = 0; i < 30; i++)
	{
		std::cout << m_NumFib[i] << " ";
	}
	std::cout << "\n";
}

bool Code::Test(int Cipher[30])
{
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		bool TestCipherIsNum = false;
		for (int j = 0; j < m_WordsQuantity; j++)
		{
			if (i != j)
			{
				if (Cipher[i] == Cipher[j])			//Проверка, нет ли в ключе одинаковых чисел
				{
					std::cout << "Error. Mumbers cannot be repeated" << "\n";
					return 0;
				}
					
			}
			
			if (Cipher[i] == m_NumFib[j])
			{
				TestCipherIsNum = true;    //Проверка, является ли число элементом последовательности Фиббоначи

			}
		}
		if (TestCipherIsNum == false)
		{
			std::cout << "Error. The number " << Cipher[i] << " does not belong to the sequence";
			return 0;
		}
	}
	return 1;
}

void Code::Decode(int Cipher[30])
{
	int Num[30];
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		for (int j = 0; j < m_WordsQuantity; j++)
		{
			if (Cipher[i] == m_NumFib[j])
			{
				Num[i] = j;
			}
		}
	}
	for (int i = 0; i < m_WordsQuantity; i++)
	{
		m_Cipher[i] = m_Words[Num[i]];
		std::cout << m_Cipher[i] << " ";
	}
	std::cout << "\n";
}