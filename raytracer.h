#pragma once
#include "pch.h"
#include "CScene.h"
#include <iostream>
#include <math.h>
#include <thread>
#include <random>


/** Glowna klasa ray tracera
 */
class CRayTrace {

public:
	CScene scene;
	CRayTrace()
	{
		//scene.parse();
	}
	bool debugtest = 0;
	vec3 Pixelcolor;
	/** Sledzenie promienia
	 */
	int rayTrace(CRay &ray, CScene* scene, float energy, bool isRefracted) {
		CObject* Intersected = Find_intersect(ray, scene->objCount, false);
		if(Intersected ==nullptr)
		{
			Pixelcolor.r += 0.f;
			Pixelcolor.g += 0.f;
			Pixelcolor.b += 0.f;

			if (Pixelcolor.r > 1)
				Pixelcolor.r = 1;
			if (Pixelcolor.g > 1)
				Pixelcolor.g = 1;
			if (Pixelcolor.b > 1)
				Pixelcolor.b = 1;
			return 0;
		}
		if(energy<=0)
		{
			return 0;
		}

		if (ray.t >= 0 && Intersected != nullptr)
		{

			vec3 p = ray.pos + ray.t * ray.dir; // punkt przecięcia
			vec3 n = Intersected->normal(&ray);
			vec3 itot(0.f, 0.f, 0.f);
			
			for (int i = 0; i < scene->lightCount; i++)
			{
				CLight *light = scene->lights[i];
				if (i == 0)
				{
					vec3 iamb = Intersected->ambient*light->ambient;
					itot += iamb;
				}
				itot += CalcColor(ray, Intersected, light, scene->cam, p, n);
			}

				Pixelcolor.r += itot.x*energy;
				Pixelcolor.g += itot.y*energy;
				Pixelcolor.b += itot.z*energy;
	

			if (Pixelcolor.r > 1)
				Pixelcolor.r = 1;
			if (Pixelcolor.g > 1)
				Pixelcolor.g = 1;
			if (Pixelcolor.b > 1)
				Pixelcolor.b = 1;

			if (isRefracted == true)
			{
				int foo;
			}

			energy -= 0.2;
			
			
			
			
			if (Intersected->reflect > 0) 
			{
				CRay reflected;
				
				
				if (Intersected->type == OBJ_SPHERE)
				{
					vec3 spherenormal = normalize(p - Intersected->pos);

					reflected.dir = reflect(ray.dir, spherenormal);
					reflected.pos = p + reflected.dir*0.001f;
					rayTrace(reflected, scene, energy, false);
					return 0;

				}
				else if (Intersected->type == OBJ_TRIANGLE)
				{
					reflected.dir = reflect(ray.dir, Intersected->normalvec);
					reflected.pos = p+reflected.dir*0.00001f;
					rayTrace(reflected, scene, energy, false);
					return 0;
				}
			
			}

		
			if (Intersected->refract > 0)
			{
				CRay refracted;

			
				if (Intersected->type == OBJ_SPHERE)
				{
					vec3 spherenormal = normalize(p - Intersected->pos);

					if(isRefracted)
					{
						spherenormal = -spherenormal;
						refracted.dir = refract(ray.dir, spherenormal, 1.f/Intersected->refractRatio);
						refracted.pos = p + refracted.dir*0.001f;
						rayTrace(refracted, scene, energy, false);
						return 0;
					}
					else
					{
						refracted.dir = refract(ray.dir, spherenormal, 1.f/Intersected->refractRatio);
						refracted.pos = p + refracted.dir*0.001f;
						rayTrace(refracted, scene, energy, true);
						return 0;
					}
					

				}
				else if (Intersected->type == OBJ_TRIANGLE)
				{
					refracted.dir = refract(ray.dir, Intersected->normalvec, Intersected->refractRatio);
					refracted.pos = p;
					rayTrace(refracted, scene, energy, false);
					return 0;
				}

			}
		}
		else
		{
			Pixelcolor.r += 0.f;
			Pixelcolor.g += 0.f;
			Pixelcolor.b += 0.f;
			return 0;
		}	
		
		debugtest = false;
	}
	CRay PrimeRay(CScene *sc, int x, int y)
	{
		CRay PRay;
		PRay.pos = scene.cam.pos;
		vec3 u, v, o, look;
		look = normalize(scene.cam.look - scene.cam.pos);
		u = cross(scene.cam.up, look);
		u = normalize(u);
		v = normalize(cross(look, u));
		o = normalize(look)*
			(float)(scene.cam.width / (2 * tan(scene.cam.FOV*3.14 / 180.f / 2.)))
			- (float)scene.cam.width / 2.f*u - (float)scene.cam.height / 2.f*v;
		mat3 d = mat3(u, v, o);
		PRay.dir = d * vec3((float)x, (float)y, 1.f);
		PRay.dir = normalize(PRay.dir);
		return PRay;
	}

	CObject *Find_intersect(CRay &ray, int objectcnt, bool isshadow)
	{
		CObject *Intersected;
		float *t = new float[objectcnt];

		for (int i = 0; i < objectcnt; i++)
		{
			t[i] = scene.obj[i]->intersect(&ray);
			if(t[i] > 0 && isshadow)
			{
				return scene.obj[i];
			}
		}

		ray.t = FLT_MAX;
		int minind = -1;
		for (int i = 0; i < objectcnt; i++)
		{
			if (t[i] <= ray.t && t[i] > 0)
			{			
				ray.t = t[i];
				minind = i;			
			}
		}
		delete t;
		if (minind >= 0)
		{
			return Intersected = scene.obj[minind];
		}
		
		return nullptr;
		
	}
	

	
	/** Glowna petla ray tracera
	 */
	int run(CScene scene/*, CImage& img*/) {
		FreeImage_Initialise();

		FIBITMAP* bitmap = FreeImage_Allocate(scene.cam.width, scene.cam.height, 24);
		RGBQUAD* color = new RGBQUAD();
		
		if (!bitmap)
			exit(1);

		//Dla każdego pixela
		for (int y = 0; y < scene.cam.height; y++) {
			std::cout << ((double)y/(double)scene.cam.height)*100 <<"%" << std::endl;
			for (int x = 0; x < scene.cam.width; x++) {			
				//Pierwotny promień
				Pixelcolor = vec3(0, 0, 0);
				CRay ray = PrimeRay(&scene, x, y);
				rayTrace(ray, &scene, 1.0, false);
				float gamma = 2.2f;
				RGBQUAD c;
				c.rgbRed = pow(Pixelcolor.x, 1. / gamma)* 255.f;
				c.rgbGreen = pow(Pixelcolor.y, 1. / gamma)* 255.f;
				c.rgbBlue = pow(Pixelcolor.z, 1. / gamma) *255.f;
				FreeImage_SetPixelColor(bitmap, x, y, &c);
			}
			
		}
		if (FreeImage_Save(FIF_PNG, bitmap, "test.png", 0))
			std::cout << "Image successfully saved!" << std::endl;

		FreeImage_DeInitialise(); //Cleanup!
		return 0;
	}

	vec3 CalcColor(CRay ray, CObject *Intersected, CLight *light, CCamera cam,  vec3 p, vec3 n)
	{
		if (Intersected->refract == 0 && Intersected->reflect == 0)
		{
			CObject *Shadow;
			CRay ShadowRay;
			ShadowRay.pos = p - ray.dir*0.0005f;
			ShadowRay.dir = normalize(light->pos - p);
			Shadow = Find_intersect(ShadowRay, scene.objCount, true);

			if (Shadow != nullptr && Shadow != Intersected && Shadow->reflect == 0 && Shadow->refract == 0)
			{
				light = new CLight(light->pos, vec3(0.1f, 0.1f, 0.1f), vec3(0, 0, 0), vec3(0, 0, 0));
			}
		}
		
		vec3 itot(0.f, 0.f, 0.f);
		vec3 L_look = normalize(light->pos - p);
		vec3 v = normalize(cam.pos - p);
		vec3 h = normalize(L_look + v);
		if (Intersected->hastex > 0 && Intersected->type == OBJ_SPHERE)
		{
			CSphere *tempSphere;
			tempSphere = dynamic_cast<CSphere *>(Intersected);
			auto r = tempSphere->r;
			auto tex = tempSphere->getTexture();
			auto c = tempSphere->pos;
			vec3 N = tempSphere->normal(&ray);
			vec3 p = ray.pos + ray.t * ray.dir;

			double temp = acos(N.z);
			double temp2 = atan2(N.y, N.x);
			double v = temp / std::_Pi;

			if (temp2 < 0) {
				temp2 = temp2 + (2 * std::_Pi);
			}

			double u = temp2 / (2 * std::_Pi);
			RGBQUAD value;

			int width = u * FreeImage_GetWidth(tex);
			int height = v * FreeImage_GetHeight(tex);



			FreeImage_GetPixelColor(tex, width, height, &value);
			itot += vec3((float)value.rgbRed / 255.f, (float)value.rgbGreen / 255.f, (float)value.rgbBlue / 255.f)*light->diffuse*dot(L_look, n);
		}
		else if (dot(L_look, n) > 0)
		{
			vec3 idiff = Intersected->diffuse*light->diffuse*dot(L_look, n);
			itot += idiff;
		}
		if (dot(n, h) > 0)
		{
			vec3 ispec = Intersected->specular*light->specular*pow(dot(n, h), Intersected->shi);
			itot += ispec;
		}
		
		return itot;
	}



};