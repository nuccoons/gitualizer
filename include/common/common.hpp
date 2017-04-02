#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

namespace gitualizer
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

	struct ModificationResponse
	{
		Modification* _mods;
		uint32_t _count;
	};
}

#endif // COMMON_HPP
