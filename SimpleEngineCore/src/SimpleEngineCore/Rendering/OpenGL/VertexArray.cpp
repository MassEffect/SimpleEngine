#include "SimpleEngineCore/Rendering/OpenGL/VertexArray.hpp"
#include "SimpleEngineCore/Log.hpp"


namespace SimpleEngine
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_id);
    };

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_id);
    };

    VertexArray::VertexArray(VertexArray&& vertexArray)noexcept
    {
        m_id = vertexArray.m_id;
        m_elements_count = vertexArray.m_elements_count;
        vertexArray.m_id = 0;
        vertexArray.m_elements_count = 0;
    };

    VertexArray& VertexArray::operator=(VertexArray&& vertexArray)noexcept
    {
        m_id = vertexArray.m_id;
        m_elements_count = vertexArray.m_elements_count;
        vertexArray.m_id = 0;
        vertexArray.m_elements_count = 0;
        return *this;
    };

    void VertexArray::add_buffer(const VertexBuffer& vertexBuffer)
    {
        bind();
        vertexBuffer.bind();

        glEnableVertexAttribArray(m_elements_count);
        glVertexAttribPointer(m_elements_count, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        ++m_elements_count;
    };

    void VertexArray::bind()const
    {
        glBindVertexArray(m_id);
    };

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    };
}
