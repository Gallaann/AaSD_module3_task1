#include "ArcGraph.h"

#include <algorithm>

ArcGraph::ArcGraph(int size)
{
    m_verticesCount = size;
}

ArcGraph::ArcGraph(const IGraph &anyGraph)
{
    m_verticesCount = anyGraph.VerticesCount();

    for (int i = 0; i < m_verticesCount; ++i)
    {
        auto nextVertices = anyGraph.GetNextVertices(i);

        for (int secondVertex : nextVertices)
        {
            auto pair = std::make_pair(i, secondVertex);
            m_arcGraph.push_back(pair);
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    auto pair = std::make_pair(from, to);

    m_arcGraph.push_back(pair);
}

int ArcGraph::VerticesCount() const
{
    return m_verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;

    for (auto edge : m_arcGraph)
    {
        if (edge.first == vertex)
        {
            result.push_back(edge.second);
        }
    }

    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;

    for (auto edge : m_arcGraph)
    {
        if (edge.second == vertex)
        {
            result.push_back(edge.first);
        }
    }

    return result;
}
