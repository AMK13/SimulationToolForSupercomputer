#include "pch.h"
#include "Processor.h"

Processor::Processor() 
{
}

Processor::Processor(TypeOfProcessor type, int id)
{
	this->type = type;
	this->id = id;
	this->engaged = false;
}


Processor::~Processor()
{
}