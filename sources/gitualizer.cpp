#include "gitualizer.hpp"

namespace gitualizer
{
	/*gitualizer::*/Gitualizer::Gitualizer()
	{
		_user = std::string();
		_repo = std::string();
	}


	/*gitualizer::*/Gitualizer::~Gitualizer()
	{
		_user.clear();
		_repo.clear();
	}


	/*gitualizer::*/Gitualizer::Gitualizer(const std::string& user, const std::string& repo)
	{
		_user = user;
		_repo = repo;
	}


	int /*gitualizer::*/Gitualizer::SetUser(const std::string& user)
	{
		_user = user;

		return 0;
	}


	int /*gitualizer::*/Gitualizer::SetRepository(const std::string& repo)
	{
		_repo = repo;

		return 0;
	}


	int /*gitualizer::*/Gitualizer::Play()
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Pause()
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Stop()
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Save(const std::string& filename)
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Load(const std::string& filename)
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Settings()
	{
		return 0;
	}


	int /*gitualizer::*/Gitualizer::Exit()
	{
		return 0;
	}
}
