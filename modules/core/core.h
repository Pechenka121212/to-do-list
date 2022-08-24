#pragma once
#include <cmath>

namespace core
{
	class Task
	{
	private:
		unsigned int* _priority;

		char* _text;

		bool* _isDone;

	public:
		Task(unsigned int* priority, char* text, bool* isDone);

		~Task();

		unsigned int* GetPriority();

		char* GetText();

		bool* GetIsDone();
	};

	class Helper
	{
	public:
		unsigned int* GetLengthCharText(char* text);

		void CopyText(char* inputText, char* resultText);

		char* SubstringCharText(char* text, unsigned int* startSubstringIndex, unsigned int* finishSubstringIndex);

		unsigned int* GetCountNumber(unsigned int* number);

		char* CharByOneNumber(unsigned int* oneNumber);

		char* ConvertIntToChar(unsigned int* number);

		char* CreateCharTask(Task* task);
	};
}

namespace interface
{
	class IDataBase
	{
	 private:
		core::Task** _tasks;

		unsigned int* _countTask;

		//char* _pathToFile;

		bool* _isCreated;

		virtual void LoadCountTask() = 0;

		virtual bool* CheckCreated() = 0;

		virtual void CreateDataBase() = 0;

		virtual void LoadTasks() = 0;

	public:

		virtual void UpdateDataBase() = 0;

		core::Task** GetTasks();

		void SetTasks(core::Task** tasks);

		unsigned int* GetCountTask();

		void SetCountTask(unsigned int* countTask);

		char* GetPathToFile();

		void SetPathToFile(char* pathToFile);

		bool* GetIsCreated();

		void SetIsCreated(bool* isCreated);
	};
}


namespace controller
{
	class TaskController
	{
	private:
		interface::IDataBase* _dataBase;

	public:
		void EditTask(core::Task* editableTask, unsigned int* newPriority, char* newText, bool* newIsDone);
	};
}

namespace interface
{
	class IUserInterface
	{
	private:
		controller::TaskController* _taskController;

	public:
		virtual void PrintTask() = 0;
	};
}
