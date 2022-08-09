#pragma once

namespace core
{
	class Task
	{
	private:

		int* _priority;

		char* _text;

		bool* _isDone;

	public:

		Task(int* priority, char* text, bool* isDone)
		{
			_priority = priority;

			_text = text;

			_isDone = isDone;
		}

		~Task()
		{
			delete _priority;

			delete[] _text;

			delete _isDone;
		}
	};
}