#include "SetGraph.h"

SetGraph::SetGraph(int size)
{
    m_setGraph.resize(size);
}

SetGraph::SetGraph(const IGraph &anyGraph)
{
    m_setGraph.resize(anyGraph.VerticesCount());

    for (int i = 0; i < anyGraph.VerticesCount(); ++i)
    {
        auto vertices = anyGraph.GetNextVertices(i);

        for (int vertex : vertices)
        {
            m_setGraph[i].insert(vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    m_setGraph[from].insert(to);
}

int SetGraph::VerticesCount() const
{
    return m_setGraph.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;

    for (auto nextVertex : m_setGraph[vertex])
    {
        result.push_back(nextVertex);
    }

    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;

    for (int i = 0; i < m_setGraph.size(); ++i)
    {
        for (auto previousVertex : m_setGraph[i])
        {
            if (previousVertex == vertex)
            {
                result.push_back(i);
            }
        }
    }

    return result;
}
