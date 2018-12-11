/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>


//Circle functions
void InitializeCircle(Circle *circ, double radius, double originX, double originY)
{
	circ->radius = radius;
	circ->originX = originX;
	circ->originY = originY;
}

double GetCircleArea(Circle *circ) 
{
return (3.14159*circ->radius*circ->radius);
}

void GetCircleBoundingBox(Circle *circ, double *bbox)
{
	bbox[0] = circ->originX - circ->radius; 
	bbox[1] = circ->originX + circ->radius;
	bbox[2] = circ->originY - circ->radius;
	bbox[3] = circ->originY + circ->radius;
}


//Rectangle functions
void InitializeRectangle(Rectangle *rect, double minX, double maxX, double minY, double maxY)
{
	rect->minX = minX;
	rect->maxX = maxX;
	rect->minY = minY;
	rect->maxY = maxY;

}

double GetRectangleArea(Rectangle *rect)
{
return (rect->maxX-rect->minX)*(rect->maxY-rect->minY);
}

void GetRectangleBoundingBox(Rectangle *rect, double *bbox) 
{
	bbox[0] = rect->minX;
	bbox[1] = rect->maxX;
	bbox[2] = rect->minY;
	bbox[3] = rect->maxY;
	
}


//Traingle functions
void InitializeTriangle(Triangle *tri, double pt1X, double pt2X, double minY, double maxY)
{
	tri->pt1X = pt1X;
	tri->pt2X = pt2X;
	tri->minY = minY;
	tri->maxY = maxY;
}

double GetTriangleArea(Triangle *tri)
{
return (tri->pt2X - tri->pt1X) * (tri->maxY - tri->minY) / 2;
}

void GetTriangleBoundingBox(Triangle *tri, double *bbox) 
{
	bbox[0] = tri->pt1X;
	bbox[1] = tri->pt2X;
	bbox[2] = tri->minY;
	bbox[3] = tri->maxY;
}
