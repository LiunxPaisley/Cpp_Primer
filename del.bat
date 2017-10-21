@echo off
rem ls -force * -include .vs -recurse | rm -r -force
del /q /s *.exe
del /q /s *.db
del /q /s *.ipch
del /q /s *.tlog
del /q /s *.pdb
del /q /s *.log
del /q /s *.idb
del /q /s *.obj
del /q /s *.ilk
del /q /s *.lastbuildstate
echo fuck off