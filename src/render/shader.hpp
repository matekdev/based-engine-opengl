#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

class Shader
{
public:
    static inline const std::string HAS_TEXTURES = "HasTextures";
    static inline const std::string CAMERA_POSITION = "CameraPosition";

    static inline const std::string PICKING_COLOR = "PickingColor";

    static inline const std::string MODEL_MATRIX = "ModelMatrix";
    static inline const std::string CAMERA_MATRIX = "CameraMatrix";
    static inline const std::string LIGHT_SPACE_MATRIX = "LightSpaceMatrix";

    static inline const std::string CAMERA_PROJECTION = "CameraProjectionMatrix";
    static inline const std::string CAMERA_VIEW_MATRIX = "CameraViewMatrix";

    static inline const std::string TEXTURE = "Texture";
    static inline const std::string SKYBOX_TEXTURE = "SkyBoxTexture";
    static inline const std::string SHADOW_MAP_TEXTURE = "ShadowMapTexture";

    static inline const std::string MATERIAL_AMBIENT = "MaterialData.Ambient";
    static inline const std::string MATERIAL_DIFFUSE = "MaterialData.Diffuse";
    static inline const std::string MATERIAL_SPECULAR = "MaterialData.Specular";
    static inline const std::string MATERIAL_SHININESS = "MaterialData.Shininess";

    static inline const std::string DIRECTIONAL_LIGHTS = "DirectionalLights";
    static inline const std::string DIRECTIONAL_LIGHT_COUNT = "DirectionalLightCount";

    static inline const std::string POINT_LIGHTS = "PointLights";
    static inline const std::string POINT_LIGHT_COUNT = "PointLightCount";

    static inline const std::string SPOT_LIGHTS = "SpotLights";
    static inline const std::string SPOT_LIGHT_COUNT = "SpotLightCount";

    static inline const std::string DIRECTION = "Direction";
    static inline const std::string POSITION = "Position";
    static inline const std::string RADIUS = "Radius";
    static inline const std::string OUTER_RADIUS = "OuterRadius";
    static inline const std::string AMBIENT = "Ambient";
    static inline const std::string DIFFUSE = "Diffuse";
    static inline const std::string SPECULAR = "Specular";
    static inline const std::string SHININESS = "Shininess";
    static inline const std::string CONSTANT = "Constant";
    static inline const std::string LINEAR = "Linear";
    static inline const std::string QUADRATIC = "Quadratic";

    static inline std::string Format(const std::string &name, const int &index)
    {
        return name + std::to_string(index);
    }

    static inline std::string Format(const std::string &name, const std::string &member, const int &index)
    {
        return name + "[" + std::to_string(index) + "]." + member;
    }

    Shader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);

    GLuint GetId();
    void Bind();
    void SetInt(const std::string &name, int i);
    void SetFloat(const std::string &name, float f);
    void SetBool(const std::string &name, bool b);
    void SetVec3(const std::string &name, const glm::vec3 &vec3);
    void SetVec4(const std::string &name, const glm::vec3 &vec4);
    void SetMat4(const std::string &name, const glm::mat4 &mat4);

private:
    GLuint _id;

    GLuint CompileShader(GLenum shaderType, const std::string &shaderSource);
};