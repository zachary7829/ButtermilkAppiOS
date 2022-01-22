//Zachary Keffaber / zachary7829, 2021/09/20, Buttermilk

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/seajson.h"
#include "lib/seaxml.h"

char *buttermilk(int mode, char *text) {
  char *returnkey;

  if (mode == 1){
  int charindex2 = 0;
  int charindex, charindex3;
  int buttermilklinecount = 1;
  signed int textpos = -1;
  int textpossave = 0;
  int incomment = 0;
  int inmulticomment = 0;
  char * actionid;
  char tmpstring[100];
  char nocommentline[100];
  char wfactions[10000] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n<plist version=\"1.0\">\n<dict>\n  <key>WFWorkflowActions</key>\n  <array>\n";

  char butternames[2369] = "{\"OpenApp\":\"is.workflow.actions.openapp\",\"GetURL\":\"is.workflow.actions.downloadurl\",\"Alert\":\"is.workflow.actions.alert\",\"Ask\":\"is.workflow.actions.ask\",\"CreateFolder\":\"is.workflow.actions.file.createfolder\",\"FilterPhotos\":\"is.workflow.actions.filter.photos\",\"Count\":\"is.workflow.actions.count\",\"Print\":\"is.workflow.actions.print\",\"GetItemFromList\":\"is.workflow.actions.getitemfromlist\",\"Comment\":\"is.workflow.actions.comment\",\"Number\":\"is.workflow.actions.number\",\"SaveFile\":\"is.workflow.actions.documentpicker.save\",\"SetVol\":\"is.workflow.actions.setvolume\",\"Date\":\"is.workflow.actions.date\",\"Flashlight\":\"is.workflow.actions.flashlight\",\"List\":\"is.workflow.actions.list\",\"RunSSH\":\"is.workflow.actions.runsshscript\",\"OpenURL\":\"is.workflow.actions.openurl\",\"GetBattery\":\"is.workflow.actions.getbatterylevel\",\"Nothing\":\"is.workflow.actions.nothing\",\"Text\":\"is.workflow.actions.gettext\",\"MakeGIF\":\"is.workflow.actions.makegif\",\"GetVar\":\"is.workflow.actions.getvariable\",\"OpenIn\":\"is.workflow.actions.openin\",\"SetVar\":\"is.workflow.actions.setvariable\",\"SetAppearance\":\"is.workflow.actions.appearance\",\"ChooseList\":\"is.workflow.actions.choosefromlist\",\"ChooseMenu\":\"is.workflow.actions.choosefrommenu\",\"Base64\":\"is.workflow.actions.base64encode\",\"AppendVar\":\"is.workflow.actions.appendvariable\",\"Hash\":\"is.workflow.actions.hash\",\"HideApp\":\"is.workflow.actions.hide.app\",\"GetShortcuts\":\"is.workflow.actions.getmyworkflows\",\"RunShortcuts\":\"is.workflow.actions.runworkflow\",\"Round\":\"is.workflow.actions.round\",\"Replace\":\"is.workflow.actions.text.replace\",\"Split\":\"is.workflow.actions.text.split\",\"Match\":\"is.workflow.actions.text.match\",\"Combine\":\"is.workflow.actions.text.combine\",\"ChangeCase\":\"is.workflow.actions.text.changecase\",\"SetBrightness\":\"is.workflow.actions.setbrightness\",\"SetClipboard\":\"is.workflow.actions.setclipboard\",\"EjectDisk\":\"is.workflow.actions.ejectdisk\",\"MakeHTMLFromRTF\":\"is.workflow.actions.gethtmlfromrichtext\",\"Homescreen\":\"is.workflow.actions.returntohomescreen\",\"SpeakText\":\"is.workflow.actions.speaktext\",\"SplitScreen\":\"is.workflow.actions.splitscreen\"}";
 
  char line[strlen(text)];
    for (unsigned int i = 0; i < strlen(text); i++) {
      // Access each char in the string
      if (text[i] == '\n'){
        buttermilklinecount++;
      }
    }
      printf("\nButtermilk Line Count: %d\n",buttermilklinecount);
    for (unsigned int i = 0; i < buttermilklinecount; i++) {
      textpos++;
      while (text[textpos] != '\n' && text[textpos] != '\0'){
        textpos++;
      }
      for (unsigned int i = 0; i < textpos; i++) {
        line[i] = text[i+textpossave];
      }
      line[textpos] = '\0';
      textpossave = textpos + 1;
    charindex = 0;
    charindex3 = 0;
    while (charindex < strlen(line)){
      if (line[charindex] == '/' && line[charindex+1] == '/'){
        incomment = 1;
      }
      if (line[charindex] == '/' && line[charindex+1] == '*'){
        inmulticomment = 1;
      }
      if (line[charindex-2] == '*' && line[charindex-1] == '/'){
        inmulticomment = 0;
      }
      if (inmulticomment == 0 && incomment == 0){
        nocommentline[charindex3] = line[charindex];
        charindex3++;
      }
      charindex++;
    }
    incomment = 0;
    nocommentline[charindex3] = '\0';
    charindex = 0;
    charindex3 = 0;
    while (1){
      if (nocommentline[charindex+charindex3] == '(' || (nocommentline[charindex+charindex3] == ' ' && charindex > 0) || (nocommentline[charindex+charindex3] == '/' && nocommentline[charindex+charindex3+1] == '/')){
        break;
      } else {
        if (nocommentline[charindex+charindex3] == ' '){
          charindex3++;
        } else {
          charindex++;
        }
      }
    }
    char params[charindex];
    memcpy(params,&nocommentline[charindex3],charindex);
    params[charindex] = '\0';
    if (!(strchr(nocommentline, '.'))) {
      actionid = getstring(params,butternames);
    } else {
      actionid = params;
    }
    if (!(actionid == NULL)){
      charindex2++;
      printf("\n\n");
      strcat(wfactions,"    <dict>\n      <key>WFWorkflowActionIdentifier</key>\n      <string>");
      strcat(wfactions,actionid);
      strcat(wfactions,"</string>\n      <key>WFWorkflowActionParameters</key>\n      <dict>\n        <key>GroupingIdentifier</key>\n        <string>Buttermilk");
      sprintf(tmpstring, "%d", charindex2);
      strcat(wfactions,tmpstring);
      strcat(wfactions,"</string>\n      </dict>\n    </dict>\n");
    }
  }
  strcat(wfactions,"  </array>\n</dict>\n</plist>");
  printf("%s",wfactions);
  returnkey = wfactions;
  printf("%sIwouldliketoremovethisbutIcant",returnkey);
  return returnkey;
  } else {
    int actionindex = 1;
    char butter[10000] = "//Buttermilk\n";
    int actionlist = countvalue("WFWorkflowActionIdentifier", text);
    printf("\nAction List: %d\n",actionlist);
    char * butteraction;
    char butternames[2080] = "{\"is.workflow.actions.hide.app\":\"HideApp\",\"is.workflow.actions.appendvariable\":\"AppendVar\",\"is.workflow.actions.alert\":\"Alert\",\"is.workflow.actions.openin\":\"OpenIn\",\"is.workflow.actions.filter.photos\":\"FilterPhotos\",\"is.workflow.actions.date\":\"Date\",\"is.workflow.actions.setvariable\":\"SetVar\",\"is.workflow.actions.text.changecase\":\"ChangeCase\",\"is.workflow.actions.openurl\":\"OpenURL\",\"is.workflow.actions.runsshscript\":\"RunSSH\",\"is.workflow.actions.openapp\":\"OpenApp\",\"is.workflow.actions.setbrightness\":\"SetBrightness\",\"is.workflow.actions.nothing\":\"Nothing\",\"is.workflow.actions.getvariable\":\"GetVar\",\"is.workflow.actions.text.replace\":\"Replace\",\"is.workflow.actions.makegif\":\"MakeGIF\",\"is.workflow.actions.documentpicker.save\":\"SaveFile\",\"is.workflow.actions.print\":\"Print\",\"is.workflow.actions.flashlight\":\"Flashlight\",\"is.workflow.actions.getmyworkflows\":\"GetShortcuts\",\"is.workflow.actions.downloadurl\":\"GetURL\",\"is.workflow.actions.setclipboard\":\"SetClipboard\",\"is.workflow.actions.getbatterylevel\":\"GetBattery\",\"is.workflow.actions.round\":\"Round\",\"is.workflow.actions.appearance\":\"SetAppearance\",\"is.workflow.actions.count\":\"Count\",\"is.workflow.actions.text.match\":\"Match\",\"is.workflow.actions.runworkflow\":\"RunShortcuts\",\"is.workflow.actions.base64encode\":\"Base64\",\"is.workflow.actions.file.createfolder\":\"CreateFolder\",\"is.workflow.actions.choosefromlist\":\"ChooseList\",\"is.workflow.actions.ask\":\"Ask\",\"is.workflow.actions.getitemfromlist\":\"GetItemFromList\",\"is.workflow.actions.choosefrommenu\":\"ChooseMenu\",\"is.workflow.actions.text.split\":\"Split\",\"is.workflow.actions.hash\":\"Hash\",\"is.workflow.actions.comment\":\"Comment\",\"is.workflow.actions.text.combine\":\"Combine\",\"is.workflow.actions.gettext\":\"Text\",\"is.workflow.actions.list\":\"List\",\"is.workflow.actions.setvolume\":\"SetVol\",\"is.workflow.actions.number\":\"Number\",\"is.workflow.actions.ejectdisk\":\"EjectDisk\",\"is.workflow.actions.gethtmlfromrichtext\":\"MakeHTMLFromRTF\",\"is.workflow.actions.returntohomescreen\":\"Homescreen\",\"is.workflow.actions.speaktext\":\"SpeakText\",\"is.workflow.actions.splitscreen\":\"SplitScreen\"}}";

    while(actionindex < actionlist+1) {
      printf("\nPassing: %s\n\n",getvalue("WFWorkflowActionIdentifier",actionindex, text));
      butteraction = getstring((getvalue("WFWorkflowActionIdentifier",actionindex, text)),butternames);
      if (!(butteraction)){
        butteraction = getvalue("WFWorkflowActionIdentifier",actionindex, text);
      }
      if (butteraction != NULL){ //Bug will no longer crash, although this doesn't really fix anything...
        strcat(butteraction,"()\n");
        strcat(butter,butteraction);
        printf("\n\n%s",butteraction);
      }
      actionindex++;
    }
    printf("%s",butter);
    returnkey = butter;
    return returnkey;
  }
  return 0;
}
