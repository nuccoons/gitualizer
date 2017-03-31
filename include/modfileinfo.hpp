#ifndef MODFILEINFO_HPP
#define MODFILEINFO_HPP

struct FileInfo //Структа содержащая информацию о конкретном файле
{
    char*       _filename;  //Имя файла в строковом виде
    char*       _author;    //Имя автора в строковом виде
    char*       _message;   //Сообщение с коментарием прилогающееся к фалу в строковом виде
    uint32_t    _ID;        //ID файла
    const char  _status;    //Статус файла 1 - добавлен, 2 - изменен, 4 - удален
};

struct FileData
{
    char*       _filename;  //Имя файла
    const char  _status;    //Статус файла 1 - добавлен, 2 - изменен, 4 - удален
};

struct Modification //Структура определяющая модификацию
{
    char*       _author;        //Имя автора модификации
    char*       _message;       //Сообщений с комментарием к модификации
    char*       _date;          //Дата произведения модификации
    FileData*   _files;         //Массив указателей на файлы в модификации
    uint32_t    _countFiles;    //Количество файлов в модификации
};

#endif // MODFILEINFO_HPP
