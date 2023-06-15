#include <iostream>

int main()
{
	const int quan = 10;
	char main_mas[quan] = { 'a','n','j','i','c','a','n','j','i','c' };
	char copy_mas[quan] = {};
	//Имеем два массива: main_mas и copy_mas. Необходимо скопировать элементы из первого во второй массив

	//Копирование при помощи цикла for и поэлементного копирования main_mas[i]=copy_mas[i] является не таким эффективным, 
	//так как циклу придется рассматривать каждый элемент отдельно. 
	//В C++ есть возможность за один и тот же промежуток времени копировать элемент разного типа данных: 
	//элемент типа char (1 байт), типа int (4 байта) и типа long long (8 байт)

	//Поэтому для более быстрого копирования необходимо перевести массив элементов типа char в тип long long. Так мы 
	//сможем за один промежуток времени скопировать не один элемент, а целых 8
	const long long* main_pointer = reinterpret_cast<const long long*>(main_mas);
	long long* copy_pointer = reinterpret_cast<long long*>(copy_mas);

	int NumOfWhole = (sizeof(char) * quan) / sizeof(long long); //количество целых long long
	int NumOfLeftovers = (sizeof(char) * quan) % sizeof(long long); //количество "нецелых" long long. эти остатки мы скопируем как просто элементы char

	//Так как в main_pointer и copy_pointer находятся указатели на начало массивов, то, призывая оператор p++, мы смещаем указатель 
	//в памяти на 8 байт.
	for (int i = 0; i < NumOfWhole; i++)
	{
		*(copy_pointer) = *(main_pointer);
		copy_pointer++; main_pointer++;
	}
	reinterpret_cast<const char*>(main_pointer);
	reinterpret_cast<char*>(copy_pointer);
	for (int j = 0; j < NumOfLeftovers; j++)
	{
		*(copy_pointer) = *(main_pointer);
		copy_pointer++; main_pointer++;
	}

	for (int t = 0; t < quan; t++)
	{
		std::cout << copy_mas[t] << " ";
	}
}
