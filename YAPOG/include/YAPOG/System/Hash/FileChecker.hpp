#ifndef YAPOG_FILECHECKER_HPP
# define YAPOG_FILECHECKER_HPP
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <vector>
# include <boost/filesystem.hpp>
# include "YAPOG/System/Hash/Md5.hpp"
# include "YAPOG/Macros.hpp"

namespace yap
{
	class YAPOG_LIB FileChecker
	{
		DISALLOW_COPY(FileChecker);
	public:
		typedef std::vector<boost::filesystem::path> t_vp;
		typedef std::vector<FileChecker*> t_vf;
		typedef std::vector<std::string> t_vs;
		FileChecker(boost::filesystem::path path);
		FileChecker(std::string filename);
		FileChecker(std::string filename, std::string md5);

		void		setfilename(std::string filename);
		void		setmd5(std::string md5);
		std::string	getfilename();
		std::string	getmd5();
		t_vf		getv();
		
		t_vs		filechecking(t_vf vc);
		t_vs		sendfiletodownload(FileChecker& fc);

	private:
		// Server checking.
		void		getfiletodownload();
		bool		compare(FileChecker* const c, FileChecker* const s);
		std::string	vectorfind(t_vf vp, FileChecker* p);

		t_vf		v_;
		boost::filesystem::path path_;
		std::string filename_;
		std::string md5_;
	};
} // namespace yap

#endif /* FILECHECKER_HPP */