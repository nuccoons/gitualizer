#ifndef COMMON_HPP
#define COMMON_HPP

const char added   = 1;
const char modified= 2;
const char removed = 4;

namespace gitualizer
{
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
