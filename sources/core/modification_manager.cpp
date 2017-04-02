#include <core/modification_manager.hpp>
#include <fstream>

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


		uint32_t ChunkSize(const Modification& m)	//Фун-ция возвращает размер всего Chunk
		{
			uint32_t size = 0;

			size += sizeof(uint32_t);	//Переменная которая содержит размер chunk
			size += sizeof(uint32_t);   //Переменная которая хранит длинну автора
			size += strlen(m._author);  //_author
			size += sizeof(uint32_t);   //Перменная которая хранит длинну _message
			size += strlen(m._message); //_message
			size += sizeof(uint32_t);   //Переменная которая хранит длинну _date
			size += strlen(m._date);	//_date
			size += sizeof(m._countFiles);	//Кол-во файлов

			for (uint32_t i = 0; i < m._countFiles; i++)
			{
				size += sizeof(uint32_t);	//Длинна _filename
				size += strlen(m._files[i]._filename);	//_filename
				size += sizeof(uint8_t);	//_status
			}

			return size;
		}


		int ModificationManager::SaveToFile(const char* filename)
		{
			uint32_t size;
			uint8_t status;
			std::ofstream file(filename, std::ios::binary);	//Открытие файла для записи в бинарном виде

			if (!file.is_open())
			{
				file.close();
				return -1;
			}

			file.write((char*)&_countMods, sizeof(_countMods));	//Запись _countMods

			for (uint32_t i = 0; i < _countMods; i++)
			{

				//Записали размер Chunk
				size = ChunkSize(_mods[i]);
				file.write((char*)&size, sizeof(size));

				//Записали _author 
				size = strlen(_mods[i]._author);
				file.write((char*)&size, sizeof(size));
				file.write((char*)_mods[i]._author, size * sizeof(_mods[i]._author[0]));

				//записали _message
				size = strlen(_mods[i]._message);
				file.write((char*)&size, sizeof(size));
				file.write((char*)_mods[i]._message, size * sizeof(_mods[i]._message[0]));

				//Записали _date
				size = strlen(_mods[i]._date);
				file.write((char*)&size, sizeof(size));
				file.write((char*)_mods[i]._date, size * sizeof(_mods[i]._date[0]));

				//Записали кол-во файлов
				file.write((char*)&_mods[i]._countFiles, sizeof(_mods[i]._countFiles));

				//Записываем файлы
				for (uint32_t j = 0; j < _mods[i]._countFiles; j++)
				{
					//Записали _filename
					size = strlen(_mods[i]._files[j]._filename);
					file.write((char*)&size, sizeof(size));
					file.write((char*)_mods[i]._files[j]._filename, size * sizeof(_mods[i]._files[j]._filename[0]));

					//Записали статус файла
					status = (uint8_t)(_mods[i]._files[j]._status);
					file.write((char*)&status, sizeof(status));

				}
			}
			file.close();	//Закрываем файл

			return 0;
		}


		int ModificationManager::LoadFromFile(const char* filename)
		{
			uint32_t size;
			uint8_t status;
			std::ifstream file(filename, std::ios::binary);	//Чтение файла в бинарном виде

			if (!file.is_open())
			{
				file.close();
				return -1;
			}

			_isOnline = false;
			file.read((char*)&_countMods, sizeof(_countMods));

			if (_mods != nullptr)
			{
				delete[] _mods;
			}

			_mods = new Modification[_countMods];
			for (uint32_t i = 0; i < _countMods; i++)
			{

				//Считали из файла _size
				file.read((char*)&size, sizeof(size));

				//Считали из файла _author
				file.read((char*)&size, sizeof(size));
				_mods[i]._author = new char[size + 1]();
				file.read((char*)_mods[i]._author, sizeof(size));

				//Считали из файла _message
				file.read((char*)&size, sizeof(size));
				_mods[i]._message = new char[size + 1]();
				file.read((char*)_mods[i]._message, sizeof(size));

				//Считали из файла _date
				file.read((char*)&size, sizeof(size));
				_mods[i]._date = new char[size + 1]();
				file.read((char*)_mods[i]._date, sizeof(size));

				file.read((char*)&_mods[i]._countFiles, sizeof (_mods[i]._countFiles));

				_mods[i]._files = new File[_mods[i]._countFiles]();

				for (uint32_t j = 0; j < _mods[i]._countFiles; j++)
				{
					//Считали из файла _filename
					file.read((char*)&size, sizeof(size));
					_mods[i]._files[j]._filename = new char[size + 1]();
					file.read((char*)_mods[i]._files[j]._filename, size * sizeof(_mods[i]._files[j]._filename[0]));

					//Считали из файла _status
					file.read((char*)&status, sizeof(status));
					_mods[i]._files[j]._status = (FileStatus)(status);

				}
			}
			file.close();	//Закрываем файл

			return 0;
		}
	}
}
