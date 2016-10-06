/**
* @author Andrew Thomas, Katie Hrenchir, Mac Crider, Yehan Li
* @file NoteReader.cpp
* @since 15 September 2016
* @brief Functionality of the NoteReader class. Returns notes from the notes.txt file
*/

#include "NoteReader.h"

NoteReader:: NoteReader(std::string file)
{
	m_file = file;
	std::ifstream inputFile(file);
	if(inputFile.good() ) {
		readNote();
		inputFile.close();
	} else {
		std::cout<< "Something went wrong with reading your file";
	}

}


std::string NoteReader:: readNote()
{
	std::ifstream inputFile(m_file);
	inputFile >> note;
	inputFile.close();
	return note;
}
