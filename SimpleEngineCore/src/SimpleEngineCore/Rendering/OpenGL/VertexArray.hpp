#pragma once
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include <glad/glad.h>

namespace SimpleEngine
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        VertexArray(const VertexArray&) = delete;
        VertexArray& operator=(const VertexArray&) = delete;
        VertexArray(VertexArray&& vertexArray)noexcept;
        VertexArray& operator=(VertexArray&& vertexArray)noexcept;

        void add_vertex_buffer(const VertexBuffer& vertexBuffer);
        void set_index_buffer(const IndexBuffer& indexBuffer);
        void bind()const;
        static void unbind();
        size_t get_indices_count()const {return m_indices_count;};


    private:
        unsigned int m_id = 0;
        unsigned int m_elements_count = 0;
        size_t m_indices_count = 0;
    };
}
