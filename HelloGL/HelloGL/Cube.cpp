#include "Cube.h"
#include "Texture2D.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z, float rot) : SceneObject(mesh, texture)
{
	_rotation = rot;
	_position.x = x;
	_position.y = y;
	_position.z = z;

	InitMaterial();
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
	glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

}
Cube::~Cube()
{

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr) 
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	else
	{
		//std::cout << _mesh->Normals << std::endl;
	}
}
void Cube::Update()
{
	_rotation += 1.0f;
	if (_rotation >= 360.0f)
	{
		_rotation = 0.0f;
	}
}

void Cube::InitMaterial()
{
	_material = new Material();
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

}

Vector3 Cube::GetPosition()
{
	return _position;
}
void Cube::SetPosition(float new_x, float new_y, float new_z)
{
	_position.x = new_x;
	_position.y = new_y;
	_position.z = new_z;
}