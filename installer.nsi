;Sharkbyteprojects
Name "NOTESHARK"
OutFile "noteshark-installer.exe"
SetCompressor lzma
RequestExecutionLevel user
LicenseData "LICENSE"
ICON "SharkNote\ico\ico.ico"
Page instfiles
Section
  SetOutPath $TEMP
  DetailPrint "Sharkbyteprojects"
  DetailPrint "Init Installer"
  DetailPrint "Download Installer"
  NSISdl::download  "http://assets.sharkbyte.bplaced.net/Noteshark.windows.exe" "ns.exe"
  Pop $R0 ;Get the return value
  StrCmp $R0 "success" +3
    DetailPrint "Download failed: $R0"
    MessageBox MB_OK "Download failed: $R0"
    Quit
  MessageBox MB_OK "Installer Starting"
  DetailPrint "EXEC Installer"
  ExecWait "ns.exe"
SectionEnd
