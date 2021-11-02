#include <dirent.h>
#include <memory.h>
#define NULL 0


int main(){
  struct dirent* dirp =opendir("/");
  struct dirent* dp;

  if(dirp == NULL){return 1;}

  int fileCount = 0;
  while ((dp = readdir(dirp)) != NULL){
      printf("%s\n", dp->d_name);
      }
  closedir(dirp);
  return 0;
}
