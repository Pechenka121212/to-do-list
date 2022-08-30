#pragma once
#include <cmath>

namespace core
{
	class Task
	{
	private:
		/// <summary>
		/// Field task priority
		/// </summary>
		unsigned int* _priority;

		/// <summary>
		/// Field task text
		/// </summary>
		char* _text;

		/// <summary>
		/// Field task status
		/// </summary>
		bool* _isDone;

	public:
		/// <summary>
		/// Task constructor
		/// </summary>
		/// <param name="priority">Task priority</param>
		/// <param name="text">Task text</param>
		/// <param name="isDone">Task status</param>
		Task(unsigned int* priority, char* text, bool* isDone);

		/// <summary>
		/// Task destructor
		/// </summary>
		~Task();

		/// <summary>
		/// Get task priority
		/// </summary>
		/// <returns>Value of the task priority field</returns>
		unsigned int* GetPriority();

		/// <summary>
		/// Get task text
		/// </summary>
		/// <returns>Value of the task text field</returns>
		char* GetText();

		/// <summary>
		/// Get task status
		/// </summary>
		/// <returns>Value of the task status field</returns>
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
