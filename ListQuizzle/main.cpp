#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Vertex
{
	wstring name;
	int x, y;

	Vertex(const wstring& name, int x, int y)
		: name(name)
		, x(x)
		, y(y)
	{

	}
};

wostream& operator<<(wostream& os, Vertex& vertex)
{
	return os << vertex.name << L"(" << vertex.x << L"," << vertex.y << L")";
}


int main()
{
	list<Vertex> vertexList;
	vertexList.push_back(Vertex(L"A", 50, 200));
	vertexList.push_back(Vertex(L"B", 20, 80));
	vertexList.push_back(Vertex(L"C", 75, 10));
	vertexList.push_back(Vertex(L"D", 130, 80));
	vertexList.push_back(Vertex(L"E", 100, 200));

	// ���� 1
	wcout << "1�� ����\n";
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		wcout << *iter << "\n";
	}
	wcout << "\n";

	// ���� 2
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		if (iter->name == L"D")
		{
			vertexList.insert(iter, Vertex(L"F", 180, 150));
		}
	}

	// 2�� Ȯ�ο� ���
	wcout << "2�� ����\n";
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		wcout << *iter << "\n";
	}
	wcout << "\n";

	// ���� 3
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		if (iter->name == L"D")
		{
			iter->x = 200;
			iter->y = 100;
		}
	}

	// 3�� Ȯ�ο� ���
	wcout << "3�� ����\n";
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		wcout << *iter << "\n";
	}
	wcout << "\n";

	// ���� 4
	vertexList.remove_if
	(
		[](const Vertex& vertex)
		{
			return vertex.name == L"C";
		}
	);


	// 4�� Ȯ�ο� ���
	wcout << "4�� ����\n";
	for (auto iter = vertexList.begin(); iter != vertexList.end(); iter++)
	{
		wcout << *iter << "\n";
	}
	wcout << "\n";



	return 0;
}