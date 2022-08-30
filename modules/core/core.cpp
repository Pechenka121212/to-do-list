#include "core.h"

/// <inheritdoc />
core::Task::Task(unsigned int* priority, char* text, bool* isDone)
{
	_priority = priority;

	_text = text;

	_isDone = isDone;
}

/// <inheritdoc />
core::Task::~Task()
{
	delete _priority;

	delete[] _text;

	delete _isDone;
}

/// <inheritdoc />
unsigned int* core::Task::GetPriority()
{
	return _priority;
}

/// <inheritdoc />
char* core::Task::GetText()
{
	return _text;
}

/// <inheritdoc />
bool* core::Task::GetIsDone()
{
	return _isDone;
}

/// <inheritdoc />
unsigned int* core::Helper::GetLengthCharText(char* text)
{
	unsigned int* lengthText = new unsigned int;

	*lengthText = 0;

	while(*(text + *lengthText) != '\0')
	{
		*lengthText += 1;
	}

	return lengthText;
}

/// <inheritdoc />
void core::Helper::CopyText(char* inputText, char* resultText)
{
	unsigned int* lengthText = GetLengthCharText(inputText);

	for(int i = 0; i < *lengthText; i++)
	{
		*(resultText + i) = *(inputText + i);
	}

	delete lengthText;
}

/// <inheritdoc />
char* core::Helper::SubstringCharText(char* text, unsigned int* startSubstringIndex, unsigned int* finishSubstringIndex)
{
	unsigned int* lengthText = new unsigned int;

	*lengthText = *finishSubstringIndex - *startSubstringIndex + 1;

	char* substringText = new char[*lengthText];

	for(int i = 0; i < *lengthText; i++)
	{
		*(substringText + i) = *(text + *startSubstringIndex + i);
	}

	*(substringText + *lengthText - 1) = '\0';

	delete lengthText;

	return substringText;
}

/// <inheritdoc />
unsigned int* core::Helper::GetCountNumber(unsigned int* number)
{
	unsigned int* countNumber = new unsigned int;

	*countNumber = 0;

	for(int i = *number; i > 1; i /= 10)
	{
		*countNumber += 1;
	}

	*countNumber += 1;

	return countNumber;
}

/// <inheritdoc />
char* core::Helper::CharByOneNumber(unsigned int* oneNumber)
{
	char* charNumber = new char;

	switch(*oneNumber)
	{
		case 0:
			*charNumber = '0';
			break;
		case 1:
			*charNumber = '1';
			break;
		case 2:
			*charNumber = '2';
			break;
		case 3:
			*charNumber = '3';
			break;
		case 4:
			*charNumber = '4';
			break;
		case 5:
			*charNumber = '5';
			break;
		case 6:
			*charNumber = '6';
			break;
		case 7:
			*charNumber = '7';
			break;
		case 8:
			*charNumber = '8';
			break;
		case 9:
			*charNumber = '9';
			break;
	}

	return charNumber;
}

/// <inheritdoc />
char* core::Helper::ConvertIntToChar(unsigned int* number)
{
	unsigned int* lengthCharNumber = GetCountNumber(number);

	char* charNumber = new char[*lengthCharNumber];

	int* tiNumber = new int;

	for(int i = 0, k = *number; i < *lengthCharNumber; i++)
	{
		unsigned int* copyNumber = new unsigned int;

		*copyNumber = k / pow(10, *lengthCharNumber - 2 - i);

		*copyNumber %= 10;

		if(i == (*lengthCharNumber - 1) && *copyNumber == 0)
		{
			continue;
		}

		char* freeChar = new char;

		freeChar = CharByOneNumber(copyNumber);

		*(charNumber + i) = *freeChar;

		delete copyNumber;

		delete freeChar;
	}

	*(charNumber + *lengthCharNumber) = '\0';

	delete lengthCharNumber;

	return charNumber;
}

/// <inheritdoc />
char* core::Helper::CreateCharTask(Task* task)
{
	unsigned int* lengthText = new unsigned int;

	char* buffer = new char[512];

	unsigned int* priority = task->GetPriority();

	char* charPriority = ConvertIntToChar(priority);

	unsigned int* lengthCharPriority = GetLengthCharText(charPriority);

	for(int i = 0; i < *lengthCharPriority; i++)
	{
		*(buffer + i) = *(charPriority + i);
	}

	*(buffer + *lengthCharPriority - 1) = '.';

	delete[] charPriority;

	char* taskText = task->GetText();

	unsigned int* lengthTaskText = GetLengthCharText(taskText);

	for(int i = *lengthCharPriority, k = 0; i < (*lengthTaskText + *lengthCharPriority + 1); i++, k++)
	{
		*(buffer + i) = *(taskText + k);
	}

	*(buffer + *lengthTaskText + *lengthCharPriority) = '.';

	unsigned int* getIsDone = new unsigned int;

	*getIsDone = *task->GetIsDone();

	char* timeChar = new char;

	if(*getIsDone)
	{
		*timeChar = '1';
	}
	else
	{
		*timeChar = '0';
	}

	*(buffer + *lengthTaskText + *lengthCharPriority + 1) = *timeChar;

	delete getIsDone;

	delete timeChar;

	*(buffer + *lengthTaskText + *lengthCharPriority + 2) = '\n';

	delete lengthCharPriority;

	delete lengthTaskText;

	for(int i = 0; i < 512; i++)
	{
		if(*(buffer + i) == '\n')
		{
			*lengthText = i;

			break;
		}
	}

	char* charTask = new char[*lengthText];

	for(int i = 0; i < *lengthText; i++)
	{
		*(charTask + i) = *(buffer + i);
	}

	delete lengthText;

	return charTask;
}

core::Task** interface::IDataBase::GetTasks()
{
	return _tasks;
}

void interface::IDataBase::SetTasks(core::Task** tasks)
{
	_tasks = tasks;
}

unsigned int* interface::IDataBase::GetCountTask()
{
	return _countTask;
}

void interface::IDataBase::SetCountTask(unsigned int* countTask)
{
	_countTask = countTask;
}

//char* interface::IDataBase::GetPathToFile()
//{
//	return _pathToFile;
//}

//void interface::IDataBase::SetPathToFile(char* pathToFile)
//{
//	_pathToFile = pathToFile;
//}

bool* interface::IDataBase::GetIsCreated()
{
	return _isCreated;
}

void interface::IDataBase::SetIsCreated(bool* isCreated)
{
	_isCreated = isCreated;
}

void controller::TaskController::EditTask(core::Task* editableTask, unsigned int* newPriority, char* newText, bool* newIsDone)
{
	editableTask->core::Task::~Task();

	core::Task* editedTask = new core::Task(newPriority, newText, newIsDone);

	editableTask = editedTask;
}
