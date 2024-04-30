#include "SceneObject.h"
#include "Texture2D.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture)
{
	_mesh = mesh;
	_texture = texture;
	
	_position.x, _position.y, _position.z = 0;
	_rotation = 0;
}
SceneObject::~SceneObject()
{

}

void SceneObject::Update()
{

}
void SceneObject::Draw()
{

}

Vector3 SceneObject::GetPosition()
{
	return _position;
}
void SceneObject::SetPosition(float new_x, float new_y, float new_z)
{
	_position.x = new_x;
	_position.y = new_y;
	_position.z = new_z;
}