#ifndef _CAMERA_H
#define _CAMERA_H


#define PI 3.14159
#include <math.h>
#include "Vector3.h"
#include "Ray3.h"

class Camera
{
private:
	Vector3 eye, front, refUp;
	Vector3 right, up;
	double fov, fovScale;


public:
	Camera() {};
	~Camera(){};

	Camera(Vector3 e, Vector3 f, Vector3 r, int v) :
		eye(e), front(f), refUp(r), fov(v) {}

	void initialize() {
		right = front.cross(refUp);
		up = right.cross(front);
		fovScale = tan(fov * 0.5 * PI / 180) * 2;
	}

	Ray3 generateRay(double x, double y) {
		Vector3 r = right.multiply((x - 0.5) * fovScale);
		Vector3 u = up.multiply((y - 0.5) * fovScale);
		return Ray3(eye, front.add(r).add(u).normalize());
	}


};


#endif