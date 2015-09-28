#ifndef _INTERSECTRESULT_H
#define _INTERSECTRESULT_H

#include "Vector3.h"
#include "Material.h"

class  IntersectResult
{
public:
	IntersectResult() {
		geometry = false; 
		distance = 10000.0;
		position.zero();
		normal.zero();
		material = new Material();
	}
	~ IntersectResult(){};

public:
	bool geometry;
	double distance;
	Vector3 position, normal;
	Material* material;
};


#endif