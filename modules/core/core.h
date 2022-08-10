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

		Task(unsigned int* priority, char* text, bool* isDone);

		~Task();
		
		unsigned int* getPriority();
		
		char* getText();
		
		bool* getIsDone();
	};
}