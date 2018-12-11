#ifndef FILTER_H
#define FILTER_H
#include <source.h>
#include <sink.h>

//Our filter class which inherits from Source and Sink
class Filter : public Source, public Sink
{
	//this allows Update to work on all filters, instead of an Update function for each filter.
	virtual void Update();
}; 

//All of the actual filters that inherit from the above filter class.
class Shrinker : public Filter
{
public:
	Shrinker();
	virtual void Execute();
};

class LRCombine : public Filter
{
public:
	LRCombine();
	virtual void Execute();
};

class TBCombine : public Filter
{
public:
	TBCombine();
	virtual void Execute();
};

class Blender : public Filter
{
private:
	double factor;
public:
	Blender();
	void SetFactor(double fact);
	virtual void Execute();
};

#endif
