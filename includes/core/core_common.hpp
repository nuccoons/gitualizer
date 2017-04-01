#ifndef CORE_COMMON_HPP
#define CORE_COMMON_HPP

#include "../common/common.hpp"

namespace gitualizer
{
    namespace core
    {
        struct FileInfo //Структа содержащая информацию о конкретном файле
        {
            char*       _filename;  //Имя файла в строковом виде
            char*       _author;    //Имя автора в строковом виде
            char*       _message;   //Сообщение с коментарием прилогающееся к фалу в строковом виде
            uint32_t    _ID;        //ID файла
            char        _status;    //Статус файла 1 - добавлен, 2 - изменен, 4 - удален
        };
    }
}

#endif // CORE_COMMON_HPP
