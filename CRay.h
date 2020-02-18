#pragma once
class CRay {
public:
	glm::vec3 pos;
	glm::vec3 dir;
	float t;
	float energy;
	CRay()
	{
		this->energy = 1.0;
	};

};