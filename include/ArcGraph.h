#pragma once

#include "IGraph.h"

struct ArcGraph : public IGraph
{
public:
    ArcGraph(int size);
    ArcGraph(const IGraph& anyGraph);

    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> m_arcGraph;
    int m_verticesCount;
};
