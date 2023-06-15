#include <iostream>

int main()
{
	const int quan = 10;
	char main_mas[quan] = { 'a','n','j','i','c','a','n','j','i','c' };
	char copy_mas[quan] = {};
	//����� ��� �������: main_mas � copy_mas. ���������� ����������� �������� �� ������� �� ������ ������

	//����������� ��� ������ ����� for � ������������� ����������� main_mas[i]=copy_mas[i] �������� �� ����� �����������, 
	//��� ��� ����� �������� ������������� ������ ������� ��������. 
	//� C++ ���� ����������� �� ���� � ��� �� ���������� ������� ���������� ������� ������� ���� ������: 
	//������� ���� char (1 ����), ���� int (4 �����) � ���� long long (8 ����)

	//������� ��� ����� �������� ����������� ���������� ��������� ������ ��������� ���� char � ��� long long. ��� �� 
	//������ �� ���� ���������� ������� ����������� �� ���� �������, � ����� 8
	const long long* main_pointer = reinterpret_cast<const long long*>(main_mas);
	long long* copy_pointer = reinterpret_cast<long long*>(copy_mas);

	int NumOfWhole = (sizeof(char) * quan) / sizeof(long long); //���������� ����� long long
	int NumOfLeftovers = (sizeof(char) * quan) % sizeof(long long); //���������� "�������" long long. ��� ������� �� ��������� ��� ������ �������� char

	//��� ��� � main_pointer � copy_pointer ��������� ��������� �� ������ ��������, ��, �������� �������� p++, �� ������� ��������� 
	//� ������ �� 8 ����.
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