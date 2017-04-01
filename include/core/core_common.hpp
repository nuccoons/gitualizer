#ifndef CORE_COMMON_HPP
#define CORE_COMMON_HPP

#include <cstdint>

namespace gitualizer
{
	namespace core
	{
		enum FileStatus
		{
			ADDED = 1,
			MODIFIED = 2,
			REMOVED = 4
		};

		struct File //Данные файла полученые из репозитория
		{
			char*		_filename;	//Имя файла
			FileStatus	_status;	//Статус файла 1 - добавлен, 2 - изменен, 4 - удален
		};

		struct Modification //Структура определяющая модификацию
		{
			char*		_author;		//Имя автора модификации
			char*		_message;		//Сообщений с комментарием к модификации
			char*		_date;			//Дата произведения модификации
			File*		_files;			//Массив указателей на файлы в модификации
			uint32_t	_countFiles;	//Количество файлов в модификации
		};

		struct FileInfo //Структа содержащая информацию о конкретном файле
		{
			char*		_filename;	//Имя файла в строковом виде
			char*		_author;	//Имя автора в строковом виде
			char*		_message;	//Сообщение с коментарием прилогающееся к фалу в строковом виде
			uint32_t	_ID;		//ID файла
			FileStatus	_status;	//Статус файла 1 - добавлен, 2 - изменен, 4 - удален
		};
	}
}

#endif // CORE_COMMON_HPP
