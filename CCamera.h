#pragma once
#include "pch.h"
using namespace glm;
class CCamera
{

public:
	vec3 pos, dir, look, up;
	int height, width;
	float FOV;
	CCamera()
	{
		this->pos = vec3(0, 0, 0);
		this->dir = vec3(0, 0, 1);
		this->look = vec3(0, 0, 0);
		this->up = vec3(0, 0, 0);
	};

	CCamera(vec3 pos, vec3 dir, vec3 look, vec3 up)
	{
		this->pos = pos;
		this->dir = dir;
		this->look = look;
		this->up = up;
	};

};

