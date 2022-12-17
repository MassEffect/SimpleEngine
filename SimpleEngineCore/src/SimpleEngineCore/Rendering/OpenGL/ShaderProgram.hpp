#pragma once
#include <glad/glad.h>

namespace SimpleEngine
{
    class ShaderProgram
    {
    public:
        ShaderProgram(const char* vertex_shader_src, const char* fragment_shader_src);
        ShaderProgram(ShaderProgram&&);
        ShaderProgram& operator=(ShaderProgram&&);
        ~ShaderProgram();

        ShaderProgram() = delete;
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;

        void bind()const;
        static void unbind();
        static bool create_shader(const char* source, const GLenum shader_type, GLuint& shader_id);
        bool isCompiled() { return m_isCompiled;};

    private:
        bool m_isCompiled = false;
        unsigned int m_id = 0;
    };
}
