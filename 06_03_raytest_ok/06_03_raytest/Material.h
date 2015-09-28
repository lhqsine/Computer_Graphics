#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Vector3.h"
#include "Ray3.h"
#include "Color.h"

class  Material
{
public:
	Material(){};
	~ Material(){};

	virtual double getReflect() { return reflectiveness; }
	virtual Color sample(Ray3 ray, Vector3 position, Vector3 normal) { return Color(0,0,0); }
//	virtual Color sample(Ray ray, Vector3 position, Vector3 normal) { return Color  getColor(Color_BLACK); }

public:
		double reflectiveness;
};

class CheckerMaterial : public Material
{
public:
	CheckerMaterial();
	~CheckerMaterial();

	CheckerMaterial(double s) : scale(s), reflectiveness(0.0) {}
	CheckerMaterial(double s, double r) : scale(s), reflectiveness(r) {}

	double getReflect() { return reflectiveness; }
	Color sample(Ray3 ray, Vector3 position, Vector3 normal) {
		if ((abs((int)(floor(position.getx() * 0.1) + floor(position.getz() * scale)) % 2)) < 1)
			return Color(0,0,0);
		return Color(1,1,1);
	}
private:
		double scale;
public:
	double reflectiveness;
};


class PhongMaterial : public Material
{
public:
	double reflectiveness;
private:
	Color diffuse, specular;
	double shiness;

public:
	PhongMaterial();
	~PhongMaterial();
	
	double getReflect() { return reflectiveness; }
	PhongMaterial(Color diff, Color spec, double shin) :
		diffuse(diff), specular(spec), shiness(shin), reflectiveness(0.0) {}
	PhongMaterial(Color diff, Color spec, double shin, double refl) :
		diffuse(diff), specular(spec), shiness(shin), reflectiveness(refl) {}

	Color sample(Ray3 ray, Vector3 position, Vector3 normal) {
		auto lightDir = Vector3(1, 1, 1).normalize();
		auto lightColor = Color(1,1,1);

		auto NdotL = normal.dot(lightDir);
		auto H = (lightDir.subtract(ray.direction)).normalize();
		auto NdotH = normal.dot(H);

		auto diffuseTerm = diffuse.multiply(max(NdotL, 0));
		auto specularTerm = specular.multiply(pow(max(NdotH, 0), shiness));
		return lightColor.modulate(diffuseTerm.add(specularTerm));
	}

};


#endif