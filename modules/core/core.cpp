#include "core.h"

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

unsigned int* core::Task::getPriority()
{
	return _priority;
}

char* core::Task::getText()
{
	return _text;
}

bool* core::Task::getIsDone()
{
	return _isDone;
}