#ifndef _PIXEL_H
#define _PIXEL_H



class Pixel
{
public:
	Pixel(){};
	~Pixel(){};
	//默认的顺序是BGR，所以数组要采用以下形式
	void setPoint(PBYTE p) { point = p; }
	void setR(double red) { point[2] = (BYTE)red; }
	void setG(double green) { point[1] = (BYTE)green; }
	void setB(double blue) { point[0] = (BYTE)blue; }

	void Next() { point += 3; }
private:
	PBYTE point;
};

#endif
