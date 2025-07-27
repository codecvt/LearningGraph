// Graph01.cpp: 定义应用程序的入口点。
//

#include "Graph01.h"
#include "graph.h"

using namespace std;

int main()
{
	// ① -- ③
	// |  .` |
	// ② -- ④
	Graph g(4);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(2, 3);

	// 从节点 0 到节点 3 的广度优先搜索
	g.bfs(0, 3);

	g.bfs(1, 2);

	cout << "Hello CMake." << endl;
	return 0;
}
