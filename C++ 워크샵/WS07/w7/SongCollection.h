/*I have done all the coding by myselfand only copied the code that my professor
provided to complete my workshopsand assignments.*/
//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           November 15, 2020
//==============================================
// Workshop :	   7
// Part     :      2
//==============================================

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds {

	struct Song {

		std::string m_artist{ "" };
		std::string m_title{ "" };
		std::string m_album{ "" };
		double m_price{ 0.0 };
		size_t m_year{ 0 };
		size_t m_length{ 0 };

	};

	class SongCollection {

		std::vector<Song> m_songs;
		std::string& trim(std::string&);

	public:

		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;

	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif 
