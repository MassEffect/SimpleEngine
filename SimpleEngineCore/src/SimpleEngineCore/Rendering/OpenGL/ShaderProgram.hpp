#pragma once
#include <glad/glad.h>
#include <glm/mat4x4.hpp>

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
        bool is_compiled() { return m_isCompiled;};
        void set_matrix4(const char* name, const glm::mat4& matrix)const;
        void set_int(const char* name, const int value)const;
        void set_float(const char* name, const float value)const;
        void set_vec3(const char* name, const glm::vec3& value)const;

    private:
        bool m_isCompiled = false;
        unsigned int m_id = 0;
    };
}
