#include "core.h"

core::Task::Task()
{
	_priority = new unsigned int;

	_text = new char[2];

	_isDone = new bool;
}

core::Task::Task(unsigned int* priority, char* text, bool* isDone)
{
	_priority = new unsigned int;

	*_priority = *priority;

	Helper helper;

	_text = new char[*helper.LengthCharText(text)];

	helper.CopyText(text, _text);

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

unsigned int* core::Helper::LengthCharText(char* text)
{
	unsigned int* lengthText = new unsigned int;

	*lengthText = 0;

	while(*(text + *lengthText) != '\0')
	{
		*lengthText += 1;
	}

	return lengthText;
}

void core::Helper::CopyText(char* inputText, char* resultText)
{
	unsigned int* lengthText = LengthCharText(inputText);

	for(int i = 0; i < *lengthText; i++)
	{
		*(resultText + i) = *(inputText + i);
	}
}

void controller::TaskController::EditTask(core::Task* editableTask, unsigned int* newPriority, char* newText, bool* newIsDone)
{
	editableTask->core::Task::~Task();

	core::Task* editedTask = new core::Task(newPriority, newText, newIsDone);

	editableTask = editedTask;
}
