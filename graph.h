#pragma once

#include <vector>
#include <list>
#include <queue>
#include <iostream>

// ����ͼ���ڽӱ��ʾ��
class Graph {
public:
	Graph(size_t v);

	// ���һ���� s �� t �ı�
	bool AddEdge(int s, int t);

	// ����������� (BFS) �� s �� t
	void bfs(int s, int t);

private:
	bool ValidEdged(int s, int t);
	void Print(const std::vector<int>& prev, int s, int t);

private:
	// ͼ�Ķ�����
	int v_;
	// �ڽӱ�
	std::vector<std::list<int>> adj_;
};
