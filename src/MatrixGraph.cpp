#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size)
{
    m_matrixGraph.resize(size);

    for (int i = 0; i < size; ++i){
        m_matrixGraph[i].resize(size, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &anyGraph)
{
    m_matrixGraph.resize(anyGraph.VerticesCount());

    for (int i = 0; i < anyGraph.VerticesCount(); ++i){
        m_matrixGraph[i].resize(anyGraph.VerticesCount(), false);
    }

    for (int i = 0; i < anyGraph.VerticesCount(); ++i)
    {
        auto nextVertices = anyGraph.GetNextVertices(i);

        for (int secondVertex : nextVertices)
        {
            m_matrixGraph[i][secondVertex] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    m_matrixGraph[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return m_matrixGraph.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> result;

    for (int i = 0; i < m_matrixGraph[vertex].size(); ++i)
    {
        if (m_matrixGraph[vertex][i])
        {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> result;

    for (int i = 0; i < m_matrixGraph.size(); ++i)
    {
        if (m_matrixGraph[i][vertex])
        {
            result.push_back(i);
        }
    }

    return result;
}
