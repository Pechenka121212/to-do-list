#pragma once
#include "core.h"
#include <filesystem>
#include <fstream>
#include <stdlib.h>

namespace database
{
    class NotepadDataBase : virtual public interface::IDataBase
    {
    private:
        void LoadCountTask() override;

        bool* CheckCreated() override;

        void CreateDataBase() override;

        void LoadTasks() override;

    public:
        NotepadDataBase();

        void UpdateDataBase() override;
    };
}
