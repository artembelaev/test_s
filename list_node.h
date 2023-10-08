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
	~List()
	{
		Clear();
	}

	ListNode * Head() const
	{
		return head;
	}

	ListNode * Tail() const
	{
		return tail;
	}

	void Clear()
	{
		ListNode * node = head;
		while (node != nullptr)
		{
			ListNode * del = node;
			node = node->next;
			delete del;
		}

		count = 0;
		head = nullptr;
		tail = nullptr;
	}

	ListNode * Append(const std::string & data, ListNode * rand = nullptr)
	{
		auto node = new ListNode;
		node->data = data;
		node->rand = rand;
		node->prev = tail;

		if (tail != nullptr)
			tail->next = node;

		if (head == nullptr)
			head = node;

		tail = node;
		++count;
		return node;
	}
	
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
