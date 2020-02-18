// RayTracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include "raytracer.h"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600
#define BPP 24
using namespace std;
int foo();
void img();
void Starter()
{
	CRayTrace *RayTracer = new CRayTrace();
	RayTracer->run(RayTracer->scene);
}

int main()
{
	Starter();
    std::cout << "Hello World!\n";
	foo();
}

int foo() {
	glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
	glm::mat4 Model = glm::mat4(1.0);
	Model[3] = glm::vec4(1.0, 1.0, 0.0, 1.0);
	glm::vec4 Transformed = Model * Position;

	return 0;
}


void img()
{
	FreeImage_Initialise();

	FIBITMAP* bitmap = FreeImage_Allocate(WIDTH, HEIGHT, BPP);
	RGBQUAD color;

	if (!bitmap)
		exit(1);

	// Draws a gradient from blue to green
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			color.rgbRed = 0;
			color.rgbGreen = (double)i / WIDTH * 255.0;
			color.rgbBlue = (double)j / HEIGHT * 255.0;

			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	if (FreeImage_Save(FIF_PNG, bitmap, "test.png", 0))
		cout << "Image successfully saved!" << endl;

	FreeImage_DeInitialise(); //Cleanup!
}

