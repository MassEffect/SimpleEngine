#pragma once
#include "SimpleEngineCore/Rendering/OpenGL/VertexBuffer.hpp"
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

        void add_buffer(const VertexBuffer& vertexBuffer);
        void bind()const;
        static void unbind();

    private:
        unsigned int m_id = 0;
        unsigned int m_elements_count = 0;
    };
}
