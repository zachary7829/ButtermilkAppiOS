//Zachary Keffaber / zachary7829, 2021/11/29, SeaXML

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * getvalue(char *dict, int occurrence, char *selectedplist) {
    printf("char getvalue reached\n");
    if (selectedplist == NULL){
      return NULL;
    }
    //system("clear");
    int tempint, testt1, testt2;
    int occurrenceindex = 1;
    int linecount = 1;
    signed int textposplist = -1;
    int textposplistsave = 0;
    int stringline = 0;
    char *returnkey;
    char dictkey[strlen(dict)];
    char line[strlen(selectedplist)];
    for (size_t i = 0; i < strlen(dict); i++) {
      // Access each char in the string
      dictkey[i] = dict[i];
    }
    dictkey[strlen(dict)] = '\0';
    for (size_t i = 0; i < strlen(selectedplist); i++) {
      // Access each char in the string
      if (selectedplist[i] == '\n'){
        linecount++;
      }
    }
    for (size_t i = 0; i < linecount; i++) {
      textposplist++;
      while (selectedplist[textposplist] != '\n' && selectedplist[textposplist] != '\0'){
        textposplist++;
      }
      for (size_t i = 0; i < textposplist-textposplistsave; i++) {
        line[i] = selectedplist[i+textposplistsave];
      }
      line[textposplist-textposplistsave] = '\0';
      textposplistsave = textposplist + 1;
      tempint = 0;
      if (stringline == 1){
        testt1 = 0;
        testt2 = 0;
        if (occurrence == occurrenceindex){
          while (tempint < strlen(line)){
            if ((line[tempint] == '>' && line[tempint-1] == 'g' && line[tempint-2] == 'n' && line[tempint-3] == 'i' && line[tempint-4] == 'r' && line[tempint-5] == 't' && line[tempint-6] == 's' && line[tempint-7] == '<') || (line[tempint] == '>' && line[tempint-1] == 'r' && line[tempint-2] == 'e' && line[tempint-3] == 'g' && line[tempint-4] == 'e' && line[tempint-5] == 't' && line[tempint-6] == 'n' && line[tempint-7] == 'i' && line[tempint-8] == '<')){
              testt1 = tempint+1;
              //reminder to not just check for < but for </string> in the future
              while (line[testt1+testt2] != '<' && testt2 < strlen(line) - testt1){
                printf("%c",line[testt1+testt2]);
                testt2++;
              }
              //ok
            }
            tempint++;
          }
          char value[testt2];
          for (size_t i = 0; i < testt2; i++) {
            value[i] = line[testt1+i];
          }
          value[testt2] = '\0';
          returnkey = value;
          return returnkey;
        }
        occurrenceindex++;
        tempint = 0;
        stringline = 0; //when string is found
      }
      while (tempint < strlen(line)){
        //printf("%c",line[tempint]);
        if (line[tempint] == '>' && line[tempint-1] == 'y' && line[tempint-2] == 'e' && line[tempint-3] == 'k' && line[tempint-4] == '<'){
          testt1 = 0;
          testt2 = 0;
          while(line[tempint+testt1+1] != '<' && testt1 < strlen(dictkey)){
            if (line[tempint+testt1+1] == dictkey[testt1]){
              //printf("%c",line[tempint+testt1+1]);
              testt2++;
            }
            testt1++;
          }
          if (testt2 == strlen(dictkey) && testt1 == strlen(dictkey)){
            stringline++;
            /*
            for(int i = 0; i < testt1; ++i) {
              //printf("%c",line[tempint+i+1]);
            }
            */
          }
        }
        tempint++;
      }
    }
    

    return 0;
}

int countvalue(char *dict, char *selectedplist) {
    printf("char countvalue reached\n");
    if (selectedplist == NULL){
      return 0;
    }
    //system("clear");
    int c = 0;
    int linecount = 1;
    signed int textposplist = -1;
    int textposplistsave = 0;
    int tempint, testt1, testt2;
    char dictkey[strlen(dict)];
    char line[strlen(selectedplist)];
    for (unsigned int i = 0; i < strlen(dict); i++) {
      // Access each char in the string
      dictkey[i] = dict[i];
    }
    dictkey[strlen(dict)] = '\0';
    for (unsigned int i = 0; i < strlen(selectedplist); i++) {
      // Access each char in the string
      if (selectedplist[i] == '\n'){
        linecount++;
      }
    }
    for (unsigned int i = 0; i < linecount; i++) {
      textposplist++;
      while (selectedplist[textposplist] != '\n' && selectedplist[textposplist] != '\0'){
        textposplist++;
      }
      for (unsigned int i = 0; i < textposplist-textposplistsave; i++) {
        line[i] = selectedplist[i+textposplistsave];
      }
      line[textposplist-textposplistsave] = '\0';
      textposplistsave = textposplist + 1;
      tempint = 0;
      while (tempint < strlen(line)){
        //printf("%c",line[tempint]);
        if (line[tempint] == '>' && line[tempint-1] == 'y' && line[tempint-2] == 'e' && line[tempint-3] == 'k' && line[tempint-4] == '<'){
          testt1 = 0;
          testt2 = 0;
          while(line[tempint+testt1+1] != '<' && testt1 < strlen(dictkey)){
            if (line[tempint+testt1+1] == dictkey[testt1]){
              //printf("%c",line[tempint+testt1+1]);
              testt2++;
            }
            testt1++;
          }
          if (testt2 == strlen(dictkey) && testt1 == strlen(dictkey)){
            c++;
            /*
            for(int i = 0; i < testt1; ++i) {
              //printf("%c",line[tempint+i+1]);
            }
            */
          }
        }
        tempint++;
      }
    }

    return c;
}
