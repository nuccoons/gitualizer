#ifndef INTERNAL_HPP
#define INTERNAL_HPP

#include <stdint.h>

namespace gitualizer
{ 
    struct FileInfo //Структа содержащая информацию о конкретном файле
    {
        char*       _filename;  //Имя файла в строковом виде
        char*       _author;    //Имя автора в строковом виде
        char*       _message;   //Сообщение с коментарием прилогающееся к фалу в строковом виде
        uint32_t    _ID;        //ID файла
        char        _status;    //Статус файла 1 - добавлен, 2 - изменен, 4 - удален
    };

    struct DirectoryInfo //Структура содержащая информацию о конкретной директории
    {
        char*           _dirname;       //Имя директории в строковом виде
        DirectoryInfo*  _dirsInfo;      //Массив указателей на дочерние дириктории
        FileInfo*       _filesInfo;     //Массив указателей на файлы содержащиеся в каталоги
        int32_t         _level;         //уровень дириктории от -1 (/)
        uint32_t        _ID;            //ID на уровне
        uint32_t        _countDirs;     //количество дочерних директорий и их ID
        uint32_t        _countFiles;    //Количество фалов в дириктории
    };

    struct StateTree //Структура вершины древа состояния
    {
        StateTree*      _child;         //Массив указателей на дочерние вершины дерева
        uint32_t*       _filesID;       //Массив ID файлов в вершине
        uint32_t        _countDirs;     //Количество дочерних вершин
        uint32_t        _countFiles;    //Количество файлов в вершине
    };

    struct Modification //Структура определяющая модификацию
    {
        char*       _author;        //Имя автора модификации
        char*       _message;       //Сообщений с комментарием к модификации
        char*       _date;          //Дата произведения модификации
        FileInfo*   _files;         //Массив указателей на файлы в модификации
        uint32_t    _countFiles;    //Количество файлов в модификации
    };

    class ModificationManager
    {
    private:
        DirectoryInfo*  _dirsInfo;  //Массив указателей на директории
    public:
        Modification* GetInitialState();            //Метод получающий начальное состояние репозитория
        Modification* GetNextModification();        //Метод получающий последующие изменения состояния репозитория
        int SaveToFile(const char* filename);       //Метод сохраняющий структуры Modification в файл...
        int LoadFromFile(const char* filename);     //...и метод их загружающий из файла
    };
}

#endif // INTERNAL_HPP
