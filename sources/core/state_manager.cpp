#include "state_manager.hpp"

namespace gitualizer
{
	namespace core
	{
		void StateManager::createTreeBranch(StateTree *rootST, uint32_t curDirID, int32_t level)
		{
			DirectoryInfo *curDir = nullptr;
			uint32_t subDirID;

			for (uint32_t i = 0; i < _countDirsInfo; i++)
			{
				if (_dirsInfo[i]._level == level && _dirsInfo[i]._ID == curDirID)
				{
					curDir = _dirsInfo + i;
					break;
				}
			}

			if (curDir)
			{
				rootST->_countFiles = curDir->_countFiles;
				rootST->_IDs = new uint32_t[rootST->_countFiles];
				for (uint32_t i = 0; i < curDir->_countFiles; i++)
				{
					rootST->_IDs[i] = curDir->_filesInfo[i]._ID;
				}

				if (curDir->_countDirs)
				{
					rootST->_countDirs = curDir->_countDirs;
					rootST->_subDirs = new StateTree[rootST->_countDirs];
					for (uint32_t i = 0; i < curDir->_countDirs; i++)
					{
						subDirID = curDir->_subDirsIDs[i];
						createTreeBranch(rootST->_subDirs + i, subDirID, level + 1);
					}
				}
				else
				{
					rootST->_countDirs = 0;
					rootST->_subDirs = nullptr;
					return;
				}
			}
		}

		const StateTree* StateManager::GetStateTree()
		{
			StateTree *rootST = new StateTree;
			createTreeBranch(rootST, 0, -1);
			return rootST;
		}
	}
}
