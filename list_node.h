#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

// ��������� ListNode �������������� ������
struct ListNode 
{
	ListNode * prev = nullptr; // ��������� �� ���������� ������� ������, ���� `nullptr` � ������ ������ ������
	ListNode * next = nullptr;
	ListNode * rand = nullptr; // ��������� �� ������������ ������� ������� ������, ���� `nullptr`
	std::string data; // ������������ ���������������� ������
};

class List 
{
public:

	void Serialize(FILE * file) // ���������� ������ � ����, ���� ������ � ������� `fopen(path, "wb")`
	{

	}

	void Deserialize(FILE * file) // �������������� ������ �� �����, ���� ������ � ������� `fopen(path, "rb")`
	{

	}
	
	

private:
	ListNode * head = nullptr;
	ListNode * tail = nullptr;
	int count = 0;
};

#endif
