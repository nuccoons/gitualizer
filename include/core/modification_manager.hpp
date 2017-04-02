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
			Modification*		_mods;
			Manager				_manager;
			uint32_t			_countMods; //счетчик модификаций
			uint32_t			_currentMod; // текущая модификация
			bool				_isOnline;

		public:
			const Modification* const GetInitialState();			//Метод получающий начальное состояние репозитория
			const Modification* const GetNextModification();		//Метод получающий последующие изменения состояния репозитория
			FileInfo GetFileInfoById(uint32_t id) const;	//Метод возвращающий информацию о файле по его ID
			int SaveToFile(const char* filename);			//Метод сохраняющий структуры Modification в файл...
			int LoadFromFile(const char* filename);			//...и метод их загружающий из файла
		};
	}
}

#endif // MODIFICATION_MANAGER_HPP
