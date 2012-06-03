#include "myGui.h"

sTate::sTate()
{
}
sTate::~sTate()
{
}
void sTate::setState(char in)
{
	this->cState = in;
}
char sTate::getState()
{
	return this->cState;
}