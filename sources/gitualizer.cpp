#include "gitualizer.hpp"

namespace gitualizer
{
	Gitualizer::Gitualizer()
	{
		_user = std::string();
		_repo = std::string();
	}


	Gitualizer::~Gitualizer()
	{
		_user.clear();
		_repo.clear();
	}


	Gitualizer::Gitualizer(const std::string& user, const std::string& repo)
	{
		_user = user;
		_repo = repo;
	}


	int Gitualizer::SetUser(const std::string& user)
	{
		_user = user;

		return 0;
	}


	int Gitualizer::SetRepository(const std::string& repo)
	{
		_repo = repo;

		return 0;
	}


	int Gitualizer::Play()
	{
		return 0;
	}


	int Gitualizer::Pause()
	{
		return 0;
	}


	int Gitualizer::Stop()
	{
		return 0;
	}


	int Gitualizer::Save(const std::string& filename)
	{
		return 0;
	}


	int Gitualizer::Load(const std::string& filename)
	{
		return 0;
	}


	int Gitualizer::Settings()
	{
		return 0;
	}


	int Gitualizer::Exit()
	{
		return 0;
	}
}
