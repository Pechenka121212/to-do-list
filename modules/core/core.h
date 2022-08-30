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
		/// <summary>
		/// Get the text length
		/// </summary>
		/// <param name="text">Char text</param>
		/// <returns>Text length not including symbol '\0'</returns>
		unsigned int* GetLengthCharText(char* text);

		/// <summary>
		/// Copy the string value into another string
		/// </summary>
		/// <param name="inputText">Source string</param>
		/// <param name="resultText">String into which you want to copy the value</param>
		void CopyText(char* inputText, char* resultText);

		/// <summary>
		/// Cut text
		/// </summary>
		/// <param name="text">Source string</param>
		/// <param name="startSubstringIndex">Cut start index</param>
		/// <param name="finishSubstringIndex">Cut finish index</param>
		/// <returns>Clipped line from the text</returns>
		char* SubstringCharText(char* text, unsigned int* startSubstringIndex, unsigned int* finishSubstringIndex);

		/// <summary>
		/// Get the count of figures in a number
		/// </summary>
		/// <param name="number">Source number</param>
		/// <returns>Count of figures in a number</returns>
		unsigned int* GetCountNumber(unsigned int* number);

		/// <summary>
		/// Convert a number to a symbol
		/// </summary>
		/// <param name="oneNumber">Source number</param>
		/// <returns>Converted number</returns>
		char* CharByOneNumber(unsigned int* oneNumber);

		/// <summary>
		/// Convert a number to a character string
		/// </summary>
		/// <param name="number">Source number</param>
		/// <returns>Converted number</returns>
		char* ConvertIntToChar(unsigned int* number);


		/// <summary>
		/// Convert an object of the Task class into a string
		/// </summary>
		/// <param name="task">Source task</param>
		/// <returns>Converted task</returns>
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
