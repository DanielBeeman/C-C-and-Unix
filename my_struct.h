/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */

typedef struct 
{
	double radius;
	double originX;
	double originY;
}Circle;

typedef struct 
{
	double pt1X;
	double pt2X;
	double minY;
	double maxY;
}Triangle;

typedef struct 
{
	double minX;
	double maxX;
	double minY;
	double maxY;
}Rectangle;


typedef union {
	Rectangle r;
	Circle c;
	Triangle t;
}ShapeUnion;

typedef enum {
	rect,
	circ,
	tria,
}ShapeType; 

struct Shape;
 
typedef struct {
	double (*GetArea)(struct Shape *);
	void (*GetBoundingBox)(struct Shape *, double *);
}FunctionTable;

struct Shape{
	ShapeUnion su;
	ShapeType st;
	FunctionTable ft;
};


