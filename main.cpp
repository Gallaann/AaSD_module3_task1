#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

#include <algorithm>
#include <iostream>
#include <queue>

/*
Дан базовый интерфейс для представления ориентированного графа:
struct IGraph {
virtual ~IGraph() {}

                    // Добавление ребра от from к to.
virtual void AddEdge(int from, int to) = 0;

virtual int VerticesCount() const  = 0;

virtual std::vector<int> GetNextVertices(int vertex) const = 0;
virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

Необходимо написать несколько реализаций интерфейса:
        ListGraph, хранящий граф в виде массива списков смежности,
        MatrixGraph, хранящий граф в виде матрицы смежности,
        SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
        ArcGraph, хранящий граф в виде одного массива пар {from, to}.
        Также необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор должен скопировать
переданный граф в создаваемый объект. Для каждого класса создавайте отдельные h и cpp файлы. Число вершин графа задается
в конструкторе каждой реализации.
*/

void DFSAUX(const IGraph &graph, int vertex, std::vector<bool> &visited, std::string &result)
{
    visited[vertex] = true;
    result += std::to_string(vertex) + " ";

    for (int nextVertex : graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFSAUX(graph, nextVertex, visited, result);
    }
}

std::string DFS(const IGraph &graph)
{
    std::string result{};
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            DFSAUX(graph, i, visited, result);
        }
    }

    return result;
}

std::string BFS(const IGraph &graph)
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::string result{};

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            std::queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();

                result += std::to_string(v) + " ";

                std::vector<int> children = graph.GetNextVertices(v);
                for (int child : children)
                {
                    if (!visited[child])
                    {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
    }

    return result;
}

void logic(std::istream &input, std::ostream &output)
{
    ListGraph listGraph(8);
    IGraph *igraph = &listGraph;

    igraph->AddEdge(0, 1);
    igraph->AddEdge(0, 2);
    igraph->AddEdge(0, 7);
    igraph->AddEdge(1, 2);
    igraph->AddEdge(1, 3);
    igraph->AddEdge(1, 5);
    igraph->AddEdge(2, 4);
    igraph->AddEdge(3, 6);

    MatrixGraph matrixGraph(listGraph);

    ArcGraph arcGraph(matrixGraph);

    SetGraph setGraph(arcGraph);

    output << "DFS:" << '\n';
    output << "ListGraph:   " << DFS(listGraph) << '\n';
    output << "MatrixGraph: " << DFS(matrixGraph) << '\n';
    output << "ArcGraph:    " << DFS(arcGraph) << '\n';
    output << "SettGraph:   " << DFS(setGraph) << '\n';

    output << '\n';

    output << "BFS:" << '\n';
    output << "ListGraph:   " << BFS(listGraph) << '\n';
    output << "MatrixGraph: " << BFS(matrixGraph) << '\n';
    output << "ArcGraph:    " << BFS(arcGraph) << '\n';
    output << "SetGraph:    " << BFS(setGraph) << '\n';
};

int main()
{
    logic(std::cin, std::cout);
    return 0;
}
