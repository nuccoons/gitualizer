#ifndef INTERNAL_HPP
#define INTERNAL_HPP

#include <stdint.h>

namespace internal
{
    struct FileInfo //Структа содержащая информацию о конкретном файле
    {
        char*   _filename, //Имя файла в строковом виде
                _author, //Имя автора в строковом виде
                _message; //Сообщение с коментарием прилогающееся к фалу в строковом виде
        int32_t _ID; //ID файла
        char _status; //Статус файла 0 - добавлен, 1 - изменен, 2 - удален (exmpl: _status = 0;)
    };

    struct DirectoryInfo //Структура содержащая информацию о конкретной директории
    {
        char* _dirname; //Имя директории в строковом виде
        int32_t     _level, //уровень дириктории от -1 (/)
                    _ID_on_level, //ID на уровне
                    _count_child_IDs, //количество дочерних директорий и их ID
                    _count_FI; //Количество фалов в дириктории
        DirectoryInfo* _child_IDs_arr; //Массив указателей на дочерние дириктории
        FileInfo* _FileInfoArr; //Массив указателей на файлы содержащиеся в каталоги
    };

    struct StateTree //Структура вершины древа состояния
    {
        StateTree* _DaughterStateTreeArr; //Массив указателей на дочерние вершины дерева
        FileInfo* _FilesArr; //Массив указателей на файлы содержащиеся в данной вершине
        int32_t     _DaugtersCount, //Количество дочерних вершин
                    _FileCount; //Количество файлов в вершине
    };

    class ModificationManager
    {
    public:
        void GetInitialState(); //Метод получающий начальное состояние репозитория
        void GetNextModification(); //Метод получающий последующие изменения состояния репозитория
        DirectoryInfo* _DirectoryInfoArr; //Массив указателей на директории
        FileInfo* _FileInfoArr; //Массив указателей на файлы
        void SaveToFile(); //Метод сохраняющий структуры Modification в файл...
        void LoadFromFile(); //...и метод их загружающий из файла
    };
}

#endif // INTERNAL_HPP
