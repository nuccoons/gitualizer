#ifndef GITUALIZER_HPP
#define GITUALIZER_HPP

#include <string>

namespace gitualizer
{
	class Gitualizer
	{
	private:
		std::string _user;
		std::string _repo;
	public:
		Gitualizer();
		~Gitualizer();
		Gitualizer(const std::string& user, const std::string& repo);

		int SetUser(const std::string& user);
		int SetRepository(const std::string& repo);

		int Play();
		int Pause();
		int Stop();

		int Save(const std::string& filename);
		int Load(const std::string& filename);

		int Settings();
		int Exit();
	};
}

#endif // GITUALIZER_HPP
