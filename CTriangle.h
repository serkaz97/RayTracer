#pragma once
#include "pch.h"
#include "CObject.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm/gtx/intersect.hpp"
#include "glm/glm/gtx/normal.hpp"
#include <iostream>
using namespace glm;
class CTriangle : public CObject {
public:

private:
	vec3 A;
	vec3 B;
	vec3 C;
public:
	CTriangle() {
		type = OBJ_TRIANGLE;
	}

	CTriangle(vec3 a, vec3 b, vec3 c, float reflect, vec3 amb, vec3 diff, vec3 spec, float shi, int refract, float refractRatio, int tex) {
		type = OBJ_TRIANGLE;
		this->A = a;
		this->B = b;
		this->C = c;
		this->reflect = reflect;
		this->ambient = amb;
		this->diffuse = diff;
		this->specular = spec;
		this->shi = shi;
		this->refract=refract;
		this->refractRatio= refractRatio;
		this->normalvec = triangleNormal(a, b, c);
		this->hastex = tex;
	}

	/** Obliczenie przeciêcia promienia z trójk¹tem */
	float intersect(CRay* ray) {
		float t = -1;
		vec2 P;
		bool IsIntersected=intersectRayTriangle(ray->pos, ray->dir, A, B, C, P, t);
		if(IsIntersected)
		{
			return t;
		}
		return t;


	}

};
