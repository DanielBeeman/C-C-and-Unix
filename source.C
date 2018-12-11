#include <source.h>

Source::Source(void)
{
	output.SetSource(this);
}


Image* Source::GetOutput()
{
	return &output;
}

void Source::Update()
{
	Execute();
}
 
