#pragma once
#include "CObject.h"
#include "algorithm"
#include <string>
using namespace glm;
class CSphere : public CObject
{
public:
	float r; /**< promien */
	
	FIBITMAP* getTexture()
	{
		return this->texture;
	}
	CSphere(CSphere &sph)
	{
		type = OBJ_SPHERE;
		this->pos = sph.pos;
		this->r = sph.r;
		this->diffuse = sph.diffuse;
		this->ambient = sph.ambient;
		this->specular = sph.specular;
		this->shi = sph.shi;
		this->reflect = sph.reflect;
		this->refract = sph.refract;
		this->refractRatio = sph.refractRatio;;

	}
	CSphere(vec3 pos, float r, float ref, vec3 amb, vec3 diff, vec3 spec, float shi, int refract, float refractRatio) {
		type = OBJ_SPHERE;
		this->pos = pos;
		this->r = r;
		this->diffuse = diff;
		this->ambient = amb;
		this->specular = spec;
		this->shi = shi;
		this->reflect = ref;
		this->refract = refract;
		this->refractRatio= refractRatio;;

	}

	CSphere(vec3 pos, float r, float ref, vec3 amb, vec3 diff, vec3 spec, float shi, int refract, float refractRatio, int tex ) {
		type = OBJ_SPHERE;
		this->pos = pos;
		this->r = r;
		this->diffuse = diff;
		this->ambient = amb;
		this->specular = spec;
		this->shi = shi;
		this->reflect = ref;
		this->refract = refract;
		this->refractRatio = refractRatio;
		this->hastex = tex;
		if(hastex>0)
		{
			LoadImage("earthmap.png");
		}
	}

	/** Obliczenie przecięcia promienia z kula */
	float intersect(CRay* ray) {
		float delta;

		float t = -1;
		vec3 v = ray->pos-pos;
		float A = dot(ray->dir, ray->dir);
		float B = dot(2.f*v, ray->dir);
		float C = dot(v, v) - (r * r);
		delta = (B * B) - (4 * A*C);
		float t1, t2;
		if (delta > 0)
		{
			
			t1 = (-B + sqrt(delta)) / (2 * A);
			t2 = (-B - sqrt(delta)) / (2 * A);
			if (t1 > 0.01 && t2 > 0.01)
				return t = std::min(t1, t2);
			else if (t1 < 0.01 && t2 >0.01)
				return t2;
			else if (t2 < 0.01 && t1 > 0.01)
				return t1;
			
		}
		else if(delta == 0)
		{
			
			return -B / (2 * A);
			
		}
		else
		{
			return -1;
		}
	}

	vec3 normal(CRay* ray)
	{
		vec3 n = normalize(ray->pos + ray->t*ray->dir-pos);
			return n;
	}

private:
	FIBITMAP* texture;
	int texHeight, texWidth;

	void LoadImage(const char* filename)
	{
		texture = FreeImage_Load(FIF_PNG, filename, PNG_DEFAULT);
		texture = FreeImage_ConvertTo24Bits(texture);


		if (FreeImage_GetBPP(texture) != 32)
		{
			FIBITMAP* tempImage = texture;
			texture = FreeImage_ConvertTo32Bits(tempImage);
		}

		texWidth = FreeImage_GetWidth(texture);
		texHeight = FreeImage_GetHeight(texture);

	}
};
