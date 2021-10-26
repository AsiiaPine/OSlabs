#include <dirent.h>
#include <memory.h>
#define NULL 0


int main(){
  struct dirent* dirp =opendir(".");
  struct dirent* dp;

  if(dirp == NULL){return 1;}

  int fileCount = 0;
  while ((dp = readdir(dirp)) != NULL){
    fileCount++;
  }
  closedir(dirp);
  dirp = opendir(".");
  struct dirent* dirents = malloc(sizeof(struct dirent) * fileCount);
  int i=0;
  while ((dp = readdir(dirp)) != NULL){
    dirents[i] = *dp;
    i++;
  }
  for (int i=0; i<fileCount-1; i++) {
    int match = 0;
    for (int j=i+1; j<fileCount; j++) {
      if (dirents[i].d_ino == dirents[j].d_ino){
        printf("%s\t", dirents[j].d_name);
        match = 1;
      }
    }
    if (match) printf("%s\ni_node:\t%d \n", dirents[i].d_name, dirents[i].d_ino);
  }
  closedir(dirp);
  return 0;
}
