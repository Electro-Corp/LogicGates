qmake -o Makefile logic.pro
echo Qmake finished...
rm main.o
rm mainwindow.o
rm moc_mainwindow.o
rm designer.o
rm logic
echo Removed Finished
make
echo Compiled
./logic