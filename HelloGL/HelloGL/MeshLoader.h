#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

#include <vector>
#include <string>
#include <sstream>

#include <iostream>
#include <fstream>
#include <cerrno>

namespace MeshLoader
{
	Mesh* Load(char* path);
};

