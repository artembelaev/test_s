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

	void Serialize(FILE * file) // сохранение списка в файл, файл открыт с помощью `fopen(path, "wb")`
	{
		ListNode * node = head;
		while (node != nullptr)
		{
			size_t data_size = node->data.size();
			fwrite(&data_size, sizeof(size_t), 1, file);
			fwrite(node->data.c_str(), sizeof(char), data_size, file);
			node = node->next;
		}
	}

	void Deserialize(FILE * file) // восстановление списка из файла, файл открыт с помощью `fopen(path, "rb")`
	{
		size_t data_size;

		while (fread(&data_size, sizeof(size_t), 1, file) == 1)
		{
			std::string data;
			data.resize(data_size);

			fread(&data[0], sizeof(char), data_size, file);
			Append(data);
		}
	}


	~List()
	{
		Clear();
	}

	int Count() const
	{
		return
			count;
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
		ListNode* node = head;
		while (node != nullptr)
		{
			ListNode* del = node;
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
	
	

private:
	ListNode * head = nullptr;
	ListNode * tail = nullptr;
	int count = 0;
};

#endif
