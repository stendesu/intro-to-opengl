#pragma once
#include "HelloGL.h"

class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);

	void Display();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);

	void Reshape(int width, int height);
}

