#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

// структуру ListNode модифицировать нельзя
struct ListNode 
{
	ListNode * prev = nullptr; // указатель на предыдущий элемент списка, либо `nullptr` в случае начала списка
	ListNode * next = nullptr;
	ListNode * rand = nullptr; // указатель на произвольный элемент данного списка, либо `nullptr`
	std::string data; // произвольные пользовательские данные
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
	
	void Serialize(FILE * file) // сохранение списка в файл, файл открыт с помощью `fopen(path, "wb")`
	{

	}

	void Deserialize(FILE * file) // восстановление списка из файла, файл открыт с помощью `fopen(path, "rb")`
	{

	}
	
	

private:
	ListNode * head = nullptr;
	ListNode * tail = nullptr;
	int count = 0;
};

#endif
