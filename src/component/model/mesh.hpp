#pragma once

#include "render/shader.hpp"
#include "vertex.hpp"
#include "texture.hpp"

#include <vector>

class Mesh
{
public:
    int IndexCount;
    int VertexCount;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

    void Delete(); // We should use a destructor here instead...
    void Render(Shader &shader);

private:
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    std::vector<Texture> _textures;
};
