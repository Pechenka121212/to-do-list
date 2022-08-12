#include "core.h"

core::Task::Task()
{
	_priority = new unsigned int;

	_text = new char[2];

	_isDone = new bool;
}

core::Task::Task(unsigned int* priority, char* text, bool* isDone)
{
	_priority = priority;

	_text = text;

	_isDone = isDone;
}

core::Task::~Task()
{
	delete _priority;

	delete[] _text;

	delete _isDone;
}

unsigned int* core::Task::GetPriority()
{
	return _priority;
}

char* core::Task::GetText()
{
	return _text;
}

bool* core::Task::GetIsDone()
{
	return _isDone;
}
