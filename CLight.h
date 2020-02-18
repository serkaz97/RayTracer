#pragma once
#include "pch.h"
using namespace glm;
class CLight {
public:

	vec3 pos;
	vec3 diffuse;
	vec3 ambient;
	vec3 specular;

	CLight(vec3 pos)
	{
		this->pos = pos;
		this->diffuse = vec3(1, 1, 1);
		this->ambient = vec3(1, 1, 1);
		this->specular = vec3(1, 1, 1);

	}

	CLight(vec3 pos, vec3 diff, vec3 amb, vec3 spec)
	{
		this->pos = pos;
		this->diffuse = diff;
		this->ambient = amb;
		this->specular = spec;

	}

};