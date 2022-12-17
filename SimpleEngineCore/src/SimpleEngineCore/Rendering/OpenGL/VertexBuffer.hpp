#pragma once
#include <glad/glad.h>

namespace SimpleEngine
{
    class VertexBuffer
    {
    public:
        enum class EUsage
        {
            Static,
            Dynamic,
            Stream
        };

        VertexBuffer(const void* data, const size_t size, const EUsage useage = VertexBuffer::EUsage::Static);
        ~VertexBuffer();

        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&& vertexBuffer) noexcept;
        VertexBuffer& operator=(VertexBuffer&& vertexBuffer) noexcept;

        void bind()const;
        static void unbind();
        static GLenum usage_to_GLenum(const VertexBuffer::EUsage usage);

    private:
        unsigned int m_id = 0;
    };
}
