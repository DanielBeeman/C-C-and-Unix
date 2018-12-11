#include <prototypes.h>


//Circle functions
void InitializeCircle(struct Shape *circl, double radius, double originX, double originY)
{
	circl -> st = circ;
	circl -> ft.GetArea = GetCircleArea;
	circl -> ft.GetBoundingBox = GetCircleBoundingBox;
	circl -> su.c.radius = radius;
	circl -> su.c.originX = originX;
	circl -> su.c.originY = originY;
}

double GetCircleArea(struct Shape *circl) 
{
return (3.14159*circl -> su.c.radius*circl -> su.c.radius);
}

void GetCircleBoundingBox(struct Shape *circl, double *bbox)
{
	bbox[0] = circl -> su.c.originX - circl -> su.c.radius; 
	bbox[1] = circl -> su.c.originX + circl -> su.c.radius; 
	bbox[2] = circl -> su.c.originY - circl -> su.c.radius; 
	bbox[3] = circl -> su.c.originY + circl -> su.c.radius; 
}


//Rectangle functions
void InitializeRectangle(struct Shape *recta, double minX, double maxX, double minY, double maxY)
{
	recta -> st = rect;
	recta -> ft.GetArea = GetRectangleArea;
	recta -> ft.GetBoundingBox = GetRectangleBoundingBox;
	recta -> su.r.minX = minX;
	recta -> su.r.maxX = maxX;
	recta -> su.r.minY = minY;
	recta -> su.r.maxY = maxY;

}

double GetRectangleArea(struct Shape *recta)
{
return (recta -> su.r.maxX-recta -> su.r.minX)*(recta -> su.r.maxY-recta -> su.r.minY);
}

void GetRectangleBoundingBox(struct Shape *recta, double *bbox) 
{
	bbox[0] = recta -> su.r.minX;
	bbox[1] = recta -> su.r.maxX;
	bbox[2] = recta -> su.r.minY;
	bbox[3] = recta -> su.r.maxY;
	
}


//Traingle functions
void InitializeTriangle(struct Shape *tri, double pt1X, double pt2X, double minY, double maxY)
{
	tri -> st = tria;
	tri -> ft.GetArea = GetTriangleArea;
	tri -> ft.GetBoundingBox = GetTriangleBoundingBox;
	tri -> su.t.pt1X = pt1X;
	tri -> su.t.pt2X = pt2X;
	tri -> su.t.minY = minY;
	tri -> su.t.maxY = maxY;
}

double GetTriangleArea(struct Shape *tri)
{
return (tri -> su.t.pt2X - tri -> su.t.pt1X) * (tri -> su.t.maxY - tri ->su.t.minY) / 2;
}

void GetTriangleBoundingBox(struct Shape *tri, double *bbox) 
{
	bbox[0] = tri -> su.t.pt1X;
	bbox[1] = tri -> su.t.pt2X;
	bbox[2] = tri -> su.t.minY;
	bbox[3] = tri -> su.t.maxY;
}




