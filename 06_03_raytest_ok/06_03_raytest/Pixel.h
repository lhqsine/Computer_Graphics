#ifndef _PIXEL_H
#define _PIXEL_H



class Pixel
{
public:
	Pixel(){};
	~Pixel(){};
	//Ĭ�ϵ�˳����BGR����������Ҫ����������ʽ
	void setPoint(PBYTE p) { point = p; }
	void setR(double red) { point[2] = (BYTE)red; }
	void setG(double green) { point[1] = (BYTE)green; }
	void setB(double blue) { point[0] = (BYTE)blue; }

	void Next() { point += 3; }
private:
	PBYTE point;
};

#endif
