#pragma once
#include "CLight.h"
#include "CObject.h"
#include "CCamera.h"
#include  "CSphere.h"
#include "CTriangle.h"

class CScene {
public:
	CCamera cam; /**< kamera */

	CObject* obj[50]; /**< lista z definicjami obiektow */
	int objCount; /**< liczba obiektow na liscie */

	CLight* lights[5];
	int lightCount;
	CScene()
	{
		parse();
	}

	/** Parsowanie pliku tektowego z informacjami o cenie.
	 *	@param - nazwa pliku
	 */
	int parse(/*char* fname*/) {
		cam.width = 1920;
		cam.height =1080;
		cam.FOV = 50.f;
		cam.pos = vec3(0.f, 3.f, -12.f);
		cam.look = vec3(0.f, 2.f, 5.f);
		cam.up = vec3(0.f, 1.f, 0.f);

		obj[0] = new CTriangle(vec3(-5.f, 0.f, -5.f), vec3(-5.f, 0.f, 5.f), vec3(5.f, 0.f, 5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.5f, 0.4f, 0.3f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);
		obj[1] = new CTriangle(vec3(5.f, 0.f, 5.f), vec3(5.f, 0.f, -5.f), vec3(-5.f, 0.f, -5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.5f, 0.4f, 0.3f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);

		obj[2] = new CTriangle(vec3(-5.f, 0.f, 5.f), vec3(5.f, 5.f, 5.f), vec3(5.f, 0.f, 5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.5f, 0.2f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);
		obj[3] = new CTriangle(vec3(-5.f, 5.f, 5.f), vec3(5.f, 5.f, 5.f), vec3(-5.f, 0.f, 5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.5f, 0.2f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);

		obj[4] = new CTriangle(vec3(5.f, 0.f, 5.f), vec3(5.f, 5.f, 5.f), vec3(5.f, 0.f, -5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);
		obj[5] = new CTriangle(vec3(5.f, 5.f, 5.f), vec3(5.f, 5.f, -5.f), vec3(5.f, 0.f, -5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);

		obj[6] = new CTriangle(vec3(-5.f, 0.f, 5.f), vec3(-5.f, 5.f, 5.f), vec3(-5.f, 0.f, -5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);
		obj[7] = new CTriangle(vec3(-5.f, 5.f, 5.f), vec3(-5.f, 5.f, -5.f), vec3(-5.f, 0.f, -5.f), 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.6f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 0, 0);
		vec3 malekulki = vec3(0.8f, 0.40f, 0.1f);
		obj[8] = new CSphere(vec3(-3.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[9] = new CSphere(vec3(-2.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[10] = new CSphere(vec3(-1.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[11] = new CSphere(vec3(-0.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[12] = new CSphere(vec3(1.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[13] = new CSphere(vec3(2.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[14] = new CSphere(vec3(3.f, 1.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);

		obj[15] = new CSphere(vec3(-3.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[16] = new CSphere(vec3(-2.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[17] = new CSphere(vec3(-1.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[18] = new CSphere(vec3(-0.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[19] = new CSphere(vec3(1.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[20] = new CSphere(vec3(2.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[21] = new CSphere(vec3(3.f, 2.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);

		obj[22] = new CSphere(vec3(-3.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[23] = new CSphere(vec3(-2.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[24] = new CSphere(vec3(-1.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[25] = new CSphere(vec3(-0.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[26] = new CSphere(vec3(1.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[27] = new CSphere(vec3(2.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[28] = new CSphere(vec3(3.f, 3.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);

		obj[29] = new CSphere(vec3(-3.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[30] = new CSphere(vec3(-2.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[31] = new CSphere(vec3(-1.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[32] = new CSphere(vec3(-0.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[33] = new CSphere(vec3(1.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[34] = new CSphere(vec3(2.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		obj[35] = new CSphere(vec3(3.f, 4.f, 4.f), 0.20f, 0, vec3(0.01f, 0.01f, 0.01f), malekulki, vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.f, 0);
		//CSphere(vec3 pos, float r, float ref, vec3 amb, vec3 diff, vec3 spec, float shi, float refract, float refractRatio, int tex)
		obj[36] = new CSphere(vec3(2.f, 1.f, -2.f), 1.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.1f, 0.1f, 0.1f), vec3(0.3f, 0.3f, 0.3f), 20, 1, 1.1f, 0);
		obj[37] = new CSphere(vec3(3.5f, 1.f, 0.f), 0.5f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.9f, 0.01f), vec3(0.8f, 0.8f, 0.8f), 20, 0, 1.0f, 0);

		obj[38] = new CSphere(vec3(0.f, 1.f, 2.5f), 1.f, 1, vec3(0.0f, 0.0f, 0.0f), vec3(0.5f, 0.5f, 0.5f), vec3(0.0f, 0.0f, 0.0f), 20, 0, 1.f, 0);
		obj[39] = new CSphere(vec3(-4.f, 1.f, 2.f), 1.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.01f, 0.01f), 20, 0, 1.0f, 1);
		//CLight(vec3 pos, vec3 diff, vec3 amb, vec3 spec)

		//lights[0] = new CLight(vec3(-5.f, 10.f, -30.f));
		//lights[1] = new CLight(vec3(0.f, 20.f, 3.f));

		lights[0] = new CLight(vec3(-5.f, 10.f, -30.f), vec3(0.1f, 0.1f, 0.1f), vec3(0.3f, 0.3f, 0.3f), vec3(0.3f, 0.3f, 0.3f));
		lights[1] = new CLight(vec3(0.f, 20.f, 3.f), vec3(0.8f, 0.8f, 0.8f), vec3(0.5f, 0.5f, 0.5f), vec3(0.5f, 0.5f, 0.5f));
		objCount = 40;
		lightCount = 2;

		return 0;
	}

};

