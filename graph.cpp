#include "graph.h"

Graph::Graph(size_t v) 
	: v_(v), adj_(v)
{
}

// ���һ���� s �� t �ı�
bool Graph::AddEdge(int s, int t)
{
	if (!ValidEdged(s, t)) {
		return false;
	}

	// ���˫���
	adj_[s].push_back(t);
	adj_[t].push_back(s);
	return true;
}

// ����������� (BFS) �� s �� t
void Graph::bfs(int s, int t)
{
	std::cout << "BFS from " << s << " to " << t << ": ";
	if (s == t) {
		return;
	}
	if (!ValidEdged(s, t)) {
		return;
	}

	std::vector<bool> visited(v_, false);
	visited[s] = true;
	std::queue<int> queue;
	queue.push(s);

	// ��¼ǰ���ڵ�
	std::vector<int> prev(v_, -1);
	while (!queue.empty()) {
		int w = queue.front();
		queue.pop();
		// �����ӵ�ǰ�ڵ�w�����������ڽӽڵ�
		const std::list<int>& neighbors = adj_[w];
		for (const int& q : neighbors) {
			if (!visited[q]) {
				visited[q] = true;
				// ��¼ǰ���ڵ�
				prev[q] = w;
				if (q == t) {
					// �ҵ�Ŀ��ڵ�t�����·��
					Print(prev, s, t);
					std::cout << std::endl;
					return;
				}
				queue.push(q);
			}
		}
	}
}

bool Graph::ValidEdged(int s, int t)
{
	if (s < 0 || s >= v_) {
		return false;
	}
	if (t < 0 || t >= v_) {
		return false;
	}
	return true;
}

void Graph::Print(const std::vector<int>& prev, int s, int t)
{
	if (prev[t] != -1 && s != t) {
		Print(prev, s, prev[t]);
	}
	std::cout << t << " ";
}
