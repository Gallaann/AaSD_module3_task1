#include "ListGraph.h"

#include <algorithm>

ListGraph::ListGraph(int size)
{
    m_listGraph.resize(size);
}

ListGraph::ListGraph(const IGraph &anyGraph)
{
    m_listGraph.resize(anyGraph.VerticesCount());

    for (int i = 0; i < anyGraph.VerticesCount(); ++i)
    {
        m_listGraph[i] = anyGraph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to)
{
    m_listGraph[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
    return m_listGraph.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    return m_listGraph[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;

    for (int i = 0; i < m_listGraph.size(); ++i)
    {
        for (int j = 0; j < m_listGraph[i].size(); ++j)
        {
            if (m_listGraph[i][j] == vertex)
            {
                result.push_back(i);
            }
        }
    }

    return result;
}
