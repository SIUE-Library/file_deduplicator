/* Project: File Deduplicator
 * Organization: The Lovejoy Library of Southern Illinois University Edwardsville
 * Department: Digital Initiatives
 * Programmer: Jacob Grubb
 * File: source.cpp
*/

//imported libraries
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

//Function Prototyping
int main(int argc, char* argv[]);
int makeHash(std::string fileName, std::hash<std::string> *hasher);
void checkFolder(std::string folderName, std::vector<fileHash> *fileHashArr, std::hash<std::string> *hasher);

struct fileHash
{
  	std::string fileName
	int hashCode
} ;


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
    		std::cerr << "Invalid Parameter. \n Correct syntax: ./deduplicate.out <root directory>";
   		exit(-1);
  	}
  
  
  	//fileHashArr <- []
  	std::vector <fileHash> fileHashArr;
  	//Get the List of Files
  	//  -Recursively
  	std::hash<std::string> hasher;
  	checkFolder(argv[1], &fileHashArr, &hasher);
  	//Create a hash of every file
  	//Create structs for each file of {pathToFile, hash}

 	 //Sort the list of structs by hash
  	std::sort(fileHashArr.begin(), fileHashArr.end(), [](const fileHash& h1, const fileHash &h2)
	{
		return h1.hashCode < h2.hashCode;
	});
  	std::vector<fileHash> duplicateArr;
  	//Print duplicate segments
  	for(int i = 1; i < fileHashArr.size(); i++)
  	{
    		int j = i + 1;
    		while(j < fileHashArr.size() && fileHashArr[i].hashCode == fileHashArr[j].hashCode)
    		{
      			//Add fileHashArr[j] to the list
			duplicateArr.push_back(fileHashArr[j]);
      			j++; 
    		}
    	//Add fileHash[i] to the list
	duplicateArr.push_back(fileHashArr[i]);
    	i = j + 1;
  	}
	//Print out the duplicates in a report
	outFile.open("Report.txt");
	if (!outFile)
	{
		std::cerr << "Error opening the output file.";
		exit(2);
	}
	for(int i = 0; i < duplicateArr.size(); i++)
	{
		outFile << duplicateArr[i].fileName << '\n';	
	}
	outFile.close();
	return 0;
}

int makeHash(std::string fileName, std::hash<string>* hasher)
{
	std::ifstream inFile;
  	//fileIO <- file.open(fileName) 
	inFile.open(fileName);
	//Load file into string stream
	std::stringstream sStream;
	sStream << inFile.rdbuf();
	//Read String stream into string object with tostring method on the string stream
	std::string fileContents;
	fileContents = sStream.str();
	//Return the hash of the string contents
  	return *hasher(fileName + fileContents);
}

void checkFolder(std::string folderName, std::vector<fileHash>* fileHashArr, std::hash<string>* hasher)
{
 	//for each subfolder in folder
 	//	checkfolder(subfolder)
  	//for each file in folder
  	//	fileHashArr <- fileHash(file + directory, makeHash(file, hasher))
}
