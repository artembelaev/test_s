#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

#include <utils/math.h>

// структуру ListNode модифицировать нельзя
struct ListNode 
{
	ListNode * prev = nullptr; // указатель на предыдущий элемент списка, либо `nullptr` в случае начала списка
	ListNode * next = nullptr;
	ListNode * rand = nullptr; // указатель на произвольный элемент данного списка, либо `nullptr`
	std::string data; // произвольные пользовательские данные
};

const int DATA_BLOCK_END = -1;

class List 
{
public:

	void Serialize(FILE * file) const // сохранение списка в файл, файл открыт с помощью `fopen(path, "wb")`
	{
		// write data and index nodes
		
		std::map<ListNode *, int> indexMap;
		int node_index = 0;

		for (ListNode * node = head; node != nullptr; node = node->next)
		{
			int data_size = node->data.size();
			fwrite(&data_size, sizeof(data_size), 1, file);
			fwrite(node->data.c_str(), sizeof(char), data_size, file);
			
			indexMap[node] = node_index;
			++node_index;
		}

		fwrite(&DATA_BLOCK_END, sizeof(DATA_BLOCK_END), 1, file);

		// write rand indexes
		int i = 0;
		for (ListNode * node = head; node != nullptr; node = node->next, ++i)
		{
			if (node->rand == nullptr)
				continue;

			auto iter = indexMap.find(node->rand);
			if (iter == indexMap.end())
				throw std::exception("node.rand points out of list");

			int rand_index = iter->second;
			fwrite(&i, sizeof(int), 1, file);
			fwrite(&rand_index, sizeof(int), 1, file);
		}
	}

	void Deserialize(FILE * file) // восстановление списка из файла, файл открыт с помощью `fopen(path, "rb")`
	{
		// read data

		int data_size;
		while (fread(&data_size, sizeof(data_size), 1, file) == 1 &&
			   data_size != DATA_BLOCK_END)
		{
			std::string data;
			data.resize(data_size);

			fread(&data[0], sizeof(char), data_size, file);

			Append(data);
		}

		// index nodes

		std::vector<ListNode *> nodes(count);
		int index = 0;
		for (ListNode * node = head; node != nullptr; node = node->next)
		{
			nodes[index] = node;
			++index;
		}

		// read rand indexes

		int indexes[2]; // node index and rand index
		while (fread(indexes, sizeof(int), 2, file) == 2)
		{
			int node_index = indexes[0];
			int rand_index = indexes[1];
	
			if (!CheckRange0(node_index, count - 1) || !CheckRange0(rand_index, count - 1))
				throw std::exception("node index out of range");
			
			nodes[node_index]->rand = nodes[rand_index];
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

private:
	ListNode * head = nullptr;
	ListNode * tail = nullptr;
	int count = 0;
};


#endif
