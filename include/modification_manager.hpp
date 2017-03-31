#ifndef MODIFICATION_MANAGER_HPP
#define MODIFICATION_MANAGER_HPP

#include <stdint.h>
#include <modfileinfo.hpp>

namespace gitualizer
{
    class ModificationManager
    {
    private:
        Modification*   caheModification;   //Массив указателей на модификация (кэш мдифифкаций)
        DirectoryInfo*  _dirsInfo;          //Массив указателей на директории
        
    public:
        Modification GetInitialState();             //Метод получающий начальное состояние репозитория
        Modification GetNextModification();         //Метод получающий последующие изменения состояния репозитория
        FileInfo GetFileInfoById(uint32_t id) const;//Метод возвращающий информацию о файле по его ID
        int SaveToFile(const char* filename);       //Метод сохраняющий структуры Modification в файл...
        int LoadFromFile(const char* filename);     //...и метод их загружающий из файла
    };
}

#endif // MODIFICATION_MANAGER_HPP
