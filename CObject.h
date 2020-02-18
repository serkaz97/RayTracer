#pragma once
#include  "pch.h"
#include "CRay.h"

class CObject {
public:
	int type; /**< rodzaj obiektu (OBJ_SPHERE, OBJ_TRIANGLE) */
	float shi;
	int reflect;
	int refract;
	float refractRatio;
	glm::vec3 normalvec;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	glm::vec3 pos;
	int hastex;
	CObject(){};
	/** Obliczenie przeciêcia promienia z obiektem */
	virtual float intersect(CRay* ray) {
		return -1;
	}
	virtual glm::vec3 normal(CRay* ray)
	{
		return glm::vec3(1, 1, 1);

	}

	
};
