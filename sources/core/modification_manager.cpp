#include "modification_manager.hpp"

namespace gitualizer
{
	namespace core
	{
		const uint32_t EDGE_LEVEL = 10; // Граница
		const uint32_t CASHING_COUNT = 100; // Кол-во запр. модиф.

		const Modification* const ModificationManager::GetNextModification()
		{
			if (_currentMod < _countMods)
			{
				if (_isOnline) // online mode
				{
					ModificationResponse response;
					if (_countMods - _currentMod <= EDGE_LEVEL)
						response = _manager.GetModifications(CASHING_COUNT); // GetModifications ( API )
					if (response._count)
					{
						Modification* tmp = new Modification[_countMods + response._count];
						Modification* tmpOffset;

						for (uint32_t i = 0; i < _countMods; ++i)
							tmp[i] = _mods[i];
						tmpOffset = tmp + _countMods;
						for (uint32_t i = 0; i < response._count; ++i)
							tmpOffset[i] = response._mods[i];
						delete[] _mods;
						_mods = tmp;
						_countMods = _currentMod + response._count;
					}
				}
				return _mods + _currentMod++;
			}
			return nullptr;
		}


		const Modification* const ModificationManager::GetInitialState()
		{
			_currentMod = 0;
			return _mods + _currentMod++;
		}
	}
}