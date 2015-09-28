#ifndef _PLANE_H
#define _PLANE_H

#include "Vector3.h"
#include "IntersectResult.h"
#include "Ray3.h"

class  Plane
{
public:
	Plane(){};
	 Plane(Vector3 p_normal, double p_d){ normal = p_normal, d = p_d;}
	 //平面表达方程式：Ax+By+Cz+D=0
	 ~ Plane(){};

	Plane copy() { return Plane(normal, d); }

	void initialize() { position = normal.multiply(d); }

	IntersectResult intersect(Ray3 r)
	{
		auto a = r.direction.dot(normal);

		if (a >= 0)
			return IntersectResult();
		
		auto b = normal.dot(r.origin.subtract(position));
		IntersectResult result;
		result.geometry = true;
		result.distance = -b / a;
		result.position = r.getPoint(result.distance);
		result.normal = normal;
		result.material = material;
		return result;

	}

public:
	Material* material;


private:
	Vector3 normal, position;
	double d;
};

#endif _PLANE_H