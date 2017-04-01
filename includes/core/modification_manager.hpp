#ifndef MODIFICATION_MANAGER_HPP
#define MODIFICATION_MANAGER_HPP

#include <cstdint>
#include "../common/common.hpp"

namespace gitualizer
{
    namespace core
    {
        class ModificationManager
        {
        private:
            Modification*   cacheModification;   //Массив указателей на модификация (кэш мдифифкаций)

        public:
            Modification GetInitialState();             //Метод получающий начальное состояние репозитория
            Modification GetNextModification();         //Метод получающий последующие изменения состояния репозитория
            FileInfo GetFileInfoById(uint32_t id) const;//Метод возвращающий информацию о файле по его ID
            int SaveToFile(const char* filename);       //Метод сохраняющий структуры Modification в файл...
            int LoadFromFile(const char* filename);     //...и метод их загружающий из файла
        };
    }
}

#endif // MODIFICATION_MANAGER_HPP
