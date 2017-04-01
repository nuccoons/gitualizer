#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include <cstdint>
#include "core_common.hpp"

namespace gitualizer
{
	namespace core
	{
		struct StateTree //Структура вершины древа состояния
		{
			StateTree*	_child;			//Массив указателей на дочерние вершины дерева
			uint32_t*	_ID;			//Массив ID файлов в вершине
			uint32_t	_countDirs;		//Количество дочерних вершин
			uint32_t	_countFiles;	//Количество файлов в вершине
		};

		class StateManager
		{
		private:
			struct DirectoryInfo //Структура содержащая информацию о конкретной директории
			{
				char*			_dirname;		//Имя директории в строковом виде
				uint32_t*		_subdirsIds;		//Массив указателей на дочерние дириктории
				FileInfo*		_filesInfo;		//Массив указателей на файлы содержащиеся в каталоги
				int32_t			_level;			//уровень дириктории от -1 (/)
				uint32_t		_ID;			//ID на уровне
				uint32_t		_countDirs;		//количество дочерних директорий и их ID
				uint32_t		_countFiles;	//Количество фалов в дириктории
			};
			DirectoryInfo*  _dirsInfo;	//Массив указателей на директории

		public:
			void AddModification(const Modification*);	//Метод, добавляющий Modification в StateTree
			const StateTree* GetStateTree() const;		//Метод, получаюший StateTree
		};
	}
}

#endif // STATE_MANAGER_HPP
