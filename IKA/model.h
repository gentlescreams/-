#ifndef MODEL_H_
#define MODEL_H_
#include"glm\glm.hpp"
#include"util.h"

typedef struct
{
	unsigned int x, y, z;
}uivec3;



class Model
{
public:
	Model();
	~Model() {}
	void Draw(GLuint id);
	void ModelDataLoad(const char *file_name);
	void Bindtexture(int id);
	void ChangeID(int id);
private:

	unsigned int nVertices;
	unsigned int iFaces;
	unsigned int nTex;
	int team;
	glm::vec3 *nomals;
	glm::vec3 *vetices;
	uivec3 *faces;
	glm::vec2 *tex;

	GLuint texture[2];
};



#endif MODEL_H_
