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
		/// <summary>
		/// Task list
		/// </summary>
		core::Task** _tasks;

		/// <summary>
		/// Count of tasks in the list
		/// </summary>
		unsigned int* _countTask;

		/// <summary>
		/// Path to the task file
		/// </summary>
		//char* _pathToFile;

		/// <summary>
		/// Database status
		/// </summary>
		bool* _isCreated;

		/// <summary>
		/// Get count of tasks in the database
		/// </summary>
		virtual void LoadCountTask() = 0;

		/// <summary>
		/// Get database status
		/// </summary>
		/// <returns>Database status</returns>
		virtual bool* CheckCreated() = 0;

		/// <summary>
		/// Create a database file
		/// </summary>
		virtual void CreateDataBase() = 0;

		/// <summary>
		/// Get the task list from database
		/// </summary>
		virtual void LoadTasks() = 0;

	public:
		/// <summary>
		/// Update the database file
		/// </summary>
		virtual void UpdateDataBase() = 0;

		/// <summary>
		/// Get the task list
		/// </summary>
		/// <returns>Task list</returns>
		core::Task** GetTasks();

		/// <summary>
		/// Set the task list
		/// </summary>
		/// <param name="tasks">Task list</param>
		void SetTasks(core::Task** tasks);

		/// <summary>
		/// Get the count of tasks
		/// </summary>
		/// <returns>Count of tasks in the list</returns>
		unsigned int* GetCountTask();

		/// <summary>
		/// Set the count of tasks
		/// </summary>
		/// <param name="countTask">Count of tasks in the list</param>
		void SetCountTask(unsigned int* countTask);

		/// <summary>
		/// Get the path to the task file
		/// </summary>
		/// <returns>Path to the task file</returns>
		char* GetPathToFile();

		/// <summary>
		/// Set the path to the task file
		/// </summary>
		/// <param name="pathToFile">Path to the task file</param>
		void SetPathToFile(char* pathToFile);

		/// <summary>
		/// Get the database status
		/// </summary>
		/// <returns>Database status</returns>
		bool* GetIsCreated();

		/// <summary>
		/// Set the database status
		/// </summary>
		/// <param name="isCreated">Database status</param>
		void SetIsCreated(bool* isCreated);
	};
}


namespace controller
{
	class TaskController
	{
	private:
		/// <summary>
		/// Database instance
		/// </summary>
		interface::IDataBase* _dataBase;

	public:
		/// <summary>
		/// Edit a task from the task list
		/// </summary>
		/// <param name="editableTask">Source task</param>
		/// <param name="newPriority">New task priority</param>
		/// <param name="newText">New task text</param>
		/// <param name="newIsDone">New task status</param>
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
