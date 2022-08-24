#include "db_notepad.h"

void database::NotepadDataBase::LoadCountTask()
{
    unsigned int* countTask = new unsigned int;

    char* buffer = new char[10];

    std::ifstream file(std::filesystem::current_path() += "/database/database.txt");

    file.getline(buffer, 10, '#');

    file.close();

    *countTask = std::atoi(buffer);

    delete[] buffer;

    interface::IDataBase::SetCountTask(countTask);
}

bool* database::NotepadDataBase::CheckCreated()
{
    bool* isCreated = new bool;

    try
    {
        for (auto &p : std::filesystem::directory_iterator("./database"))
        {
            if (!std::filesystem::is_regular_file(p.status()))
                continue; // Пропускаем, если это не простой файл, а папка или что-то другое

            std::string name(p.path().filename());

            // Тут делаем с путем то, что нужно
            if(name == "database.txt")
            {
                *isCreated = true;
            }
            else
            {
                *isCreated = false;
            }
        }
    }
    catch(const std::filesystem::filesystem_error &err)
    {
        *isCreated = false;
    }

    return isCreated;
}

void database::NotepadDataBase::CreateDataBase()
{
    std::filesystem::create_directory("database");

    std::ofstream file(std::filesystem::current_path() += "/database/database.txt");

    file << "0#\n";

    file.close();
}

void database::NotepadDataBase::LoadTasks()
{
    std::ifstream file(std::filesystem::current_path() += "/database/database.txt");

    unsigned int* countTask = interface::IDataBase::GetCountTask();

    core::Task** tasks = new core::Task*[*countTask];

    unsigned int* numberTask = new unsigned int;

    *numberTask = 0;

    char* buffer = new char[512];

    file.getline(buffer, 512, '\n');

    delete[] buffer;

    for(int i = 0; i < *countTask; i++)
    {
        char* buffer = new char[512];

        unsigned int* startDotIndex = new unsigned int;

        unsigned int* finishDotIndex = new unsigned int;

        *startDotIndex = 0;

        *finishDotIndex = 511;

        file.getline(buffer, 512, '\n');

        for(int i = 0; i < 511; i++)
        {
            if(*(buffer + i) == '.')
            {
                *startDotIndex += i;

                break;
            }
        }

        for(int i = 0; i < 511; i++)
        {
            if(*(buffer + (*finishDotIndex - i)) == '.')
            {
                *finishDotIndex -= i;

                break;
            }
        }

        core::Helper help;

        unsigned int* startFinishCharIndex = new unsigned int;

        *startFinishCharIndex = 0;

        char* taskPriorityChar = help.SubstringCharText(buffer, startFinishCharIndex, startDotIndex);

        unsigned int* taskPriority = new unsigned int;

        *taskPriority = std::atoi(taskPriorityChar);

        *startFinishCharIndex = 511;

        delete taskPriorityChar;

        *startDotIndex += 1;

        char* taskText = help.SubstringCharText(buffer, startDotIndex, finishDotIndex);

        delete startDotIndex;

        *finishDotIndex += 1;

        char* taskIsDoneChar = help.SubstringCharText(buffer, finishDotIndex, startFinishCharIndex);

        delete finishDotIndex;

        bool* taskIsDone = new bool;

        *taskIsDone = std::atoi(taskIsDoneChar);

        delete taskIsDoneChar;

        delete startFinishCharIndex;

        delete[] buffer;

        core::Task* task = new core::Task(taskPriority, taskText, taskIsDone);

        *(tasks + *numberTask) = task;

        *numberTask += 1;
    }

    delete numberTask;

    file.close();

    interface::IDataBase::SetTasks(tasks);
}

database::NotepadDataBase::NotepadDataBase()
{
    interface::IDataBase::SetIsCreated(CheckCreated());

    if(*interface::IDataBase::GetIsCreated())
    {
        LoadCountTask();

        LoadTasks();
    }
    else
    {
        CreateDataBase();

        unsigned int* countTask = new unsigned int;

        *countTask = 0;

        interface::IDataBase::SetCountTask(countTask);
    }
}

void database::NotepadDataBase::UpdateDataBase()
{
    core::Helper help;

    std::ifstream readFile(std::filesystem::current_path() += "/database/database.txt");

    unsigned int* oldCountTask = new unsigned int;

    char* buffer = new char[10];

    readFile.getline(buffer, 10, '#');

    *oldCountTask = std::atoi(buffer);

    delete[] buffer;

    unsigned int* lengthOldText = new unsigned int;

    *lengthOldText = 512 * (*oldCountTask);

    char* oldText = new char[*lengthOldText];

    unsigned int* realLengthOldText = new unsigned int;

    *realLengthOldText = 0;

    char* someChar = new char;

    *someChar = readFile.get();

    delete someChar;

    while(!readFile.eof())
    {
        *(oldText + *realLengthOldText) = readFile.get();

        *realLengthOldText += 1;
    }

    readFile.close();

    delete lengthOldText;

    char* realOldText = new char[*realLengthOldText];

    for(int i = 0; i < *realLengthOldText; i++)
    {
        *(realOldText + i) = *(oldText + i);
    }

    *(realOldText + *realLengthOldText - 1) = '\0';
    *(realOldText + *realLengthOldText) = '\n';

    delete[] oldText;

    delete realLengthOldText;

    std::ofstream writeFile(std::filesystem::current_path() += "/database/database.txt");

    unsigned int* newCountTask = interface::IDataBase::GetCountTask();

    core::Task** tasks = interface::IDataBase::GetTasks();

    writeFile << *interface::IDataBase::GetCountTask();

    writeFile << '#';

    writeFile << '\n';

    writeFile << realOldText;

    writeFile.close();

    writeFile.open(std::filesystem::current_path() += "/database/database.txt", std::ios::app);

    for(int i = *oldCountTask; i < *newCountTask; i++)
    {
        char* charTask = help.CreateCharTask(*(tasks + i));

        writeFile << charTask;
    }

    writeFile.close();

    delete oldCountTask;
}
