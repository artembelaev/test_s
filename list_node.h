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

	void Clear()
	{
		ListNode * node = head;
		while (node != nullptr)
		{
			node = node->next;
			ListNode * del = node;
			delete del;
		}

		count = 0;
		head = nullptr;
		tail = nullptr;
	}

	ListNode * Append(const std::string & _data, ListNode * _rand = nullptr)
	{
		auto node = new ListNode{ prev = tail, _rand = rand, data = _data };

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
