/* Project: File Deduplicator
 * Organization: The Lovejoy Library of Southern Illinois University Edwardsville
 * Department: Digital Initiatives and
 * Programmer: Jacob Grubb
 * File: source.cpp
*/

//imported libraries
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//Function Prototyping
int main(int argc, char* argv[]);
int makeHash(string fileName);
void checkFolder(string folderName, vector<fileHash> *fileHashArr);

struct fileHash
{
  string fileName
  int hashCode
} ;


int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cerr << "Invalid Parameter. \n Correct syntax: ./deduplicate.out <root directory>";
    exit(-1) ;
  }
  
  
  //fileHashArr <- []
  std::vector <fileHash> fileHashArr;
  //Get the List of Files
  //  -Recursively, perhaps?
  //    checkfolder(folder)
  checkFolder(argv[1], &fileHashArr);
  //Create a hash of every file
  //Create structs for each file of {pathToFile, hash}

  //Sort the list of structs by hash
  std::sort(fileHashArr.begin(), fileHashArr.end(), [](const fileHash& h1, const fileHas &h2)
	{
		return h1.hashCode < h2.hashCode;
	});
  
  //Print duplicate segments
  for(int i = 1; i < fileHashArr.size(); i++)
  {
    int j = i + 1;
    while(j < fileHashArr.size() && fileHashArr[i].hashCode == fileHashArr[j].hashCode)
    {
      //Add fileHashArr[j] to the list
      j++; 
    }
    //Add fileHash[i] to the list
    i = j;
  }
}

int makeHash(string fileName)
{
  return 0;
}

void checkFolder(string folderName, vector<fileHash>* fileHashArr)
{
  //      for each subfolder in folder
  //        checkfolder(subfolder)
  //      for each file in folder
  //        fileHashArr <- fileHash(file + directory, makeHash(file))
}
