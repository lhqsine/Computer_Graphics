#ifndef _SPHERE_H
#define _SPHERE_H

#include "Vector3.h"
#include "IntersectResult.h"
#include "Ray3.h"

class Sphere
{
public:
	Material* material;
private:
	Vector3 center;
	double radius, sqrRadius;

public:
	Sphere() {};
	~Sphere() {};

	Sphere(Vector3 c, double r) : center(c), radius(r) {}
	Sphere copy() { return Sphere(center.copy(), radius); }
	void initialize() { sqrRadius = radius * radius; }
	
	IntersectResult intersect(Ray3 ray) {
		Vector3 v = ray.origin.subtract(center);
		double a0 = v.sqrLength() - sqrRadius;
		double DdotV = ray.direction.dot(v);
		
		if (DdotV <= 0) {
			double discr = DdotV * DdotV - a0;
			if (discr >= 0) {
				IntersectResult result; // = IntersectResult();
				result.geometry = true;
				result.distance = -DdotV - sqrt(discr);
				result.position = ray.getPoint(result.distance);
				result.normal = result.position.subtract(center).normalize();
				result.material = material;
				return result;
			}
		}
		return IntersectResult();
	}

};

#endif