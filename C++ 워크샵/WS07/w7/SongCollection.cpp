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

#include <fstream>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"

using namespace std;
namespace sdds {

	string& SongCollection::trim(string& src) {

		while (src.length() > 0 && src[0] == ' ')
			src.erase(0, 1);

		while (src.length() > 0 && src[src.length() - 1] == ' ')
			src.erase(src.length() - 1, 1);

		return src;
	}

	SongCollection::SongCollection(const char* filename) {

		ifstream file(filename);

		if (!file) {
			throw "The filename is incorrect!";
			return;
		}

		while (file) {

			string b = "";
			getline(file, b);

			if (file) {

				Song song;
				trim(song.m_title = b.substr(0, 25));
				trim(song.m_artist = b.substr(25, 25));
				trim(song.m_album = b.substr(50, 25));

				try {
					song.m_year = stoi(b.substr(75, 5));
				}
				catch (...) {
					song.m_year = 0;
				}

				song.m_length = stoi(b.substr(80, 5));
				song.m_price = stod(b.substr(85));
				m_songs.push_back(song);
			}
		}
		file.close();
	}

	void SongCollection::display(ostream& out) const {

		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& src) { out << src << endl; });
		size_t total = 0;
		for_each(m_songs.begin(), m_songs.end(), [&](const Song& src) { total += src.m_length; });
		out << "----------------------------------------------------------------------------------------\n";
		string str = "Total Listening Time: ";

		str += to_string(total / 3600);
		str += ":";
		str += to_string(total % 3600 / 60);
		str += ":";
		str += to_string(total % 3600 % 60);
		out << "| " << setw(84) << str << " |" << endl;
	}

	ostream& operator<<(ostream& out, const Song& theSong) {

		out << "| " << left << setw(20) << theSong.m_title
			<< " | " << left << setw(15) << theSong.m_artist
			<< " | " << left << setw(20) << theSong.m_album
			<< " | " << right << setw(6) << (theSong.m_year > 0 ? to_string(theSong.m_year) : "")
			<< " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << setfill(' ')
			<< " | " << setprecision(2) << fixed << theSong.m_price << " |";

		return out;
	}

	void SongCollection::sort(string fieldname) {

		if (fieldname == "title") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) { return a.m_title < b.m_title; });
		}

		else if (fieldname == "album") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) { return a.m_album < b.m_album; });
		}

		else if (fieldname == "length") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) { return a.m_length < b.m_length; });
		}
	}

	void SongCollection::cleanAlbum() {
		for_each(m_songs.begin(), m_songs.end(), [](Song& s) {return s.m_album == "[None]" ? s.m_album = "" : s.m_album; });
	}

	bool SongCollection::inCollection(string artist) const {
		return any_of(m_songs.begin(), m_songs.end(), [&artist](const Song& s) {return s.m_artist == artist ? true : false; });
	}

	list<Song> SongCollection::getSongsForArtist(string artist) const {

		auto count = count_if(m_songs.begin(), m_songs.end(), [&artist](const Song& s) {return s.m_artist == artist; });
		list<Song> songs(count);

		copy_if(m_songs.begin(), m_songs.end(), songs.begin(), [&artist](const Song& s) {return s.m_artist == artist; });

		return songs;
	}
}