#pragma once

#include <vector>
#include <list>
#include <queue>
#include <iostream>

// 无向图的邻接表表示法
class Graph {
public:
	Graph(size_t v);

	// 添加一条从 s 到 t 的边
	bool AddEdge(int s, int t);

	// 广度优先搜索 (BFS) 从 s 到 t
	void bfs(int s, int t);

private:
	bool ValidEdged(int s, int t);
	void Print(const std::vector<int>& prev, int s, int t);

private:
	// 图的顶点数
	int v_;
	// 邻接表
	std::vector<std::list<int>> adj_;
};
