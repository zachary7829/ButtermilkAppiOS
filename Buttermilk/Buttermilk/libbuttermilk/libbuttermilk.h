//Zachary Keffaber / zachary7829, 2021/09/20, Buttermilk

#include <stdio.h>
#include <string.h>
#include "lib/seajson.h"

char *buttermilk(char *text) {
  char *returnkey;
  int c = 0;
  int termination = 0;
  long size = 0;
  int charindex = 0;
  int charindex2 = 0;
  int tempint = 0;
  char tmpstring[100];
  char wfactions[10000] = "{\"WFWorkflowClientVersion\":\"100\",\"WFWorkflowClientRelease\":\"3.0\",\"WFWorkflowMinimumClientVersion\":\"100\",\"WFWorkflowMinimumClientVersionString\":\"100\",\"WFWorkflowImportQuestions\":[],\"WFWorkflowTypes\":[\"NCWidget\",\"WatchKit\"],\"WFWorkflowInputContentItemClasses\":[\"WFAppStoreAppContentItem\",\"WFArticleContentItem\",\"WFContactContentItem\",\"WFDateContentItem\",\"WFEmailAddressContentItem\",\"WFGenericFileContentItem\",\"WFImageContentItem\",\"WFiTunesProductContentItem\",\"WFLocationContentItem\",\"WFDCMapsLinkContentItem\",\"WFAVAssetContentItem\",\"WFPDFContentItem\",\"WFPhoneNumberContentItem\",\"WFRichTextContentItem\",\"WFSafariWebPageContentItem\",\"WFStringContentItem\",\"WFURLContentItem\"],\"WFWorkflowIcon\":{\"WFWorkflowIconStartColor\":431817727,\"WFWorkflowIconGlyphNumber\":61440},\"WFWorkflowActions\":[";
  char * actionid;
  FILE *fp;

  //fp = fopen("libbuttermilk/language/actionnamesrev.json", "r");
    /*
  fseek(fp, 0, SEEK_END); // seek to end of file
  size = ftell(fp); // get current file pointer
  fseek(fp, 0, SEEK_SET); // seek back to beginning of file
     */
  char butternames[2369] = "{\"OpenApp\":\"is.workflow.actions.openapp\",\"GetURL\":\"is.workflow.actions.downloadurl\",\"Alert\":\"is.workflow.actions.alert\",\"Ask\":\"is.workflow.actions.ask\",\"CreateFolder\":\"is.workflow.actions.file.createfolder\",\"FilterPhotos\":\"is.workflow.actions.filter.photos\",\"Count\":\"is.workflow.actions.count\",\"Print\":\"is.workflow.actions.print\",\"GetItemFromList\":\"is.workflow.actions.getitemfromlist\",\"Comment\":\"is.workflow.actions.comment\",\"Number\":\"is.workflow.actions.number\",\"SaveFile\":\"is.workflow.actions.documentpicker.save\",\"SetVol\":\"is.workflow.actions.setvolume\",\"Date\":\"is.workflow.actions.date\",\"Flashlight\":\"is.workflow.actions.flashlight\",\"List\":\"is.workflow.actions.list\",\"RunSSH\":\"is.workflow.actions.runsshscript\",\"OpenURL\":\"is.workflow.actions.openurl\",\"GetBattery\":\"is.workflow.actions.getbatterylevel\",\"Nothing\":\"is.workflow.actions.nothing\",\"Text\":\"is.workflow.actions.gettext\",\"MakeGIF\":\"is.workflow.actions.makegif\",\"GetVar\":\"is.workflow.actions.getvariable\",\"OpenIn\":\"is.workflow.actions.openin\",\"SetVar\":\"is.workflow.actions.setvariable\",\"SetAppearance\":\"is.workflow.actions.appearance\",\"ChooseList\":\"is.workflow.actions.choosefromlist\",\"ChooseMenu\":\"is.workflow.actions.choosefrommenu\",\"Base64\":\"is.workflow.actions.base64encode\",\"AppendVar\":\"is.workflow.actions.appendvariable\",\"Hash\":\"is.workflow.actions.hash\",\"HideApp\":\"is.workflow.actions.hide.app\",\"GetShortcuts\":\"is.workflow.actions.getmyworkflows\",\"RunShortcuts\":\"is.workflow.actions.runworkflow\",\"Round\":\"is.workflow.actions.round\",\"Replace\":\"is.workflow.actions.text.replace\",\"Split\":\"is.workflow.actions.text.split\",\"Match\":\"is.workflow.actions.text.match\",\"Combine\":\"is.workflow.actions.text.combine\",\"ChangeCase\":\"is.workflow.actions.text.changecase\",\"SetBrightness\":\"is.workflow.actions.setbrightness\",\"SetClipboard\":\"is.workflow.actions.setclipboard\",\"EjectDisk\":\"is.workflow.actions.ejectdisk\",\"MakeHTMLFromRTF\":\"is.workflow.actions.gethtmlfromrichtext\",\"Homescreen\":\"is.workflow.actions.returntohomescreen\",\"SpeakText\":\"is.workflow.actions.speaktext\",\"SplitScreen\":\"is.workflow.actions.splitscreen\"}";
  //fscanf(fp, "%s", butternames);
  //fclose(fp);
 
  //fp=fopen("testwrite.txt", "w");
  //fprintf(fp, "aba");
  //fclose(fp);
 
 
  char line[100];
  while (c < strlen(text)) {
    line[c] = text[c];
    c++;
  }
  line[c] = '\0';
  while (termination == 0){
    termination = 1;
    charindex2++;
    charindex = 0;
    tempint = 0;
    while (tempint == 0){
      if (line[charindex] == '('){
        tempint++;
      } else {
      }
      charindex++;
    }
    char params[charindex-1];
    memcpy(params,&line[0],charindex-1);
    params[charindex-1] = '\0';
    charindex = 0;
    tempint = 0;
    if (charindex2 > 1){
      strcat(wfactions,",");
    }
    strcat(wfactions,"{\"WFWorkflowActionIdentifier\":\"");
    for(int i = 0; i < sizeof params; ++i) {
      if (line[i] == '.'){
        charindex++;
      }
    }
    if (charindex == 0) {
      actionid = getstring(params,butternames);
    } else {
      actionid = params;
    }
    printf("\n\n");
    strcat(wfactions,actionid);
    strcat(wfactions,"\",\"WFWorkflowActionParameters\":{\"UUID\":\"Buttermilk");
    sprintf(tmpstring, "%d", charindex2);
    strcat(wfactions,tmpstring);
    strcat(wfactions,"\"}}");
  }
  strcat(wfactions,"]}");
  fclose(fp);
  printf("%s",wfactions);
  returnkey = wfactions;
  return *returnkey;
  return 0;
}
