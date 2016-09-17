/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file NoteReader.h
* @since 15 September 2016
* @brief Header of the NoteReader class. Returns notes from the notes.txt file
*/

#ifndef NOTEREADER_H
#define NOTEREADER_H

#include <fstream>
#include <string>
#include <iostream>

class NoteReader
{

	public:
	NoteReader(std::string file);
	std::string readNote();

	private:
	std::string m_file;
	std::string note;

};

#endif
