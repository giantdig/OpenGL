#pragma once

#include <GL/glew.h>
#include <iostream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();

#ifdef DEBUG
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#else
#define CLCall(x) x

#endif // DEBUG

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


class Renderer
{
public:
    void clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

};