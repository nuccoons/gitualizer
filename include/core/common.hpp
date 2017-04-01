#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

const char ADDED    = 1;
const char MODIFIED = 2;
const char REMOVED  = 4;

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

    struct File //Данные файла полученые из репозитория
    {
        char*       _filename;  //Имя файла
        char        _status;    //Статус файла 1 - добавлен, 2 - изменен, 4 - удален
    };

    struct Modification //Структура определяющая модификацию
    {
        char*       _author;        //Имя автора модификации
        char*       _message;       //Сообщений с комментарием к модификации
        char*       _date;          //Дата произведения модификации
        File*       _files;         //Массив указателей на файлы в модификации
        uint32_t    _countFiles;    //Количество файлов в модификации
    };
}

#endif // COMMON_HPP
