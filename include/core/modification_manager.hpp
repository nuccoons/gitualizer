#ifndef MODIFICATION_MANAGER_HPP
#define MODIFICATION_MANAGER_HPP

#include <cstdint>
#include "core_common.hpp"

namespace gitualizer
{
	namespace core
	{
		class ModificationManager
		{
		private:
			Modification*	_mods;
			Modification*	_cache;		//Массив указателей на модификация (кэш мдифифкаций)

		public:
			Modification GetInitialState() const;			//Метод получающий начальное состояние репозитория
			Modification GetNextModification() const;		//Метод получающий последующие изменения состояния репозитория
			FileInfo GetFileInfoById(uint32_t id) const;	//Метод возвращающий информацию о файле по его ID
			int SaveToFile(const char* filename);			//Метод сохраняющий структуры Modification в файл...
			int LoadFromFile(const char* filename);			//...и метод их загружающий из файла
		};
	}
}

#endif // MODIFICATION_MANAGER_HPP
