#ifndef _VECTOR3_H
#define _VECTOR3_H

#include <Math.h>

class  Vector3
{
public:
	Vector3() {x = 0.0f; y = 0.0f; z = 0.0f;}
	Vector3(double p_x, double p_y, double p_z) { x = p_x; y = p_y; z = p_z;}
	~ Vector3(){};

	double getx() { return x; }
	double gety() { return y; }
	double getz() { return z; }


	Vector3 copy() { return Vector3(x, y, z); }
	double length() { return sqrt(x * x + y * y + z * z); }
	double sqrLength() { return x * x + y * y + z * z; }
	
	Vector3 normalize() {
		double inv = 1 / length();
		return Vector3(x * inv, y * inv, z * inv);
	}

	Vector3 negate() { return Vector3(-x, -y, -z); }
	Vector3 add(Vector3 v) { return Vector3(x + v.x, y + v.y, z + v.z); }
	Vector3 subtract(Vector3 v) { return Vector3(x - v.x, y - v.y, z - v.z); }
	Vector3 multiply(double d) { return Vector3(x * d, y * d, z * d); }
	
	Vector3 divide(double d) {
		double invd = 1 / d;
		return Vector3(x * invd, y * invd, z * invd);
	}

	double dot(Vector3 v) { return x * v.x + y * v.y + z * v.z; }
	
	Vector3 cross(Vector3 v) { 
	return Vector3(-z * v.y + y * v.z, z * v.x - x * v.z, -y * x + x * v.y); 
	}
	
	Vector3 zero() { return Vector3(0, 0, 0); }

private:
	double x, y, z;
};


#endif