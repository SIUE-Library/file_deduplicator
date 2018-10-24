/* Project: File Deduplicator
 * Organization: The Lovejoy Library of Southern Illinois University Edwardsville
 * Department: Digital Initiatives and
 * Programmer: Jacob Grubb
 * File: source.cpp
*/

//imported libraries
#import <string>

//Function Prototyping
int main();
int makeHash(string fileName);

struct fileHash
{
  string fileName
  int fileHash
} ;


int main()
{
  //fileHashArr <- []

  //Get the List of Files
  //  -Recursively, perhaps?
  //    checkfolder(folder)

  //Create a hash of every file

  //Create structs for each file of {pathToFile, hash}

  //Sort the list of structs by hash

  //Identify segments of duplicates

  //Print duplicate segments
}

int makeHash(string fileName)
{
  
  return 0;
}

void checkFolder(string folderName)
{
  //      for each subfolder in folder
  //        checkfolder(subfolder)
  //      for each file in folder
  //        fileHashArr <- fileHash(file + directory, makeHash(file))
}
