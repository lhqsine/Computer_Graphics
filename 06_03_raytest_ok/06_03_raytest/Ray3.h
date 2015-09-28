#ifndef _RAY_H
#define _RAY_H

#include "Vector3.h"

// r(t) = o + td, t >= 0;

class  Ray3
{
public:
	Ray3(){};
	~ Ray3(){};

	Ray3(Vector3 o,Vector3 d){origin = o; direction = d;}

	Vector3 getPoint(double t){
		return origin.add(direction.multiply(t));
	}

public:
	Vector3 origin, direction;
};

#endif