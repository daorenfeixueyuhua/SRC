g++ -c $1 -o example.o -D FREEGLUT_STATIC -I"C:\MinGW\include\GL"
g++ example.o -o test.exe -L"C:\MinGW\lib" -lfreeglut_static -lglaux -lopengl32 -lglu32 -lglut32 -lwinmm -lgdi32 -Wl,--subsystem,windows
rm ./example.o
echo "compile successful!"