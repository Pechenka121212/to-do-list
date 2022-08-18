#pragma once

namespace core
{
	class Task
	{
	private:
		unsigned int* _priority;

		char* _text;

		bool* _isDone;

	public:
		Task();

		Task(unsigned int* priority, char* text, bool* isDone);

		~Task();
		
		unsigned int* GetPriority();
		
		char* GetText();
		
		bool* GetIsDone();
	};

	class Helper
	{
	public:
		unsigned int* LengthCharText(char* text);

		void CopyText(char* inputText, char* resultText);
	};
}

namespace interface
{
	class IDataBase
	{
	 private:
		core::Task* _tasks;

		unsigned int* _countTask;

		char* _pathToFile;

		bool* _isCreated;

		virtual void CreateDataBase() = 0;

		virtual void UpdateDataBase() = 0;

	public:
		virtual void LoadTasks() = 0;

		virtual void SaveTasks() = 0;
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
