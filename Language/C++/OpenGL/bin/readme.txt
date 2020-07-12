-lglut32 -lglu32 -lopengl32
gcc -c -o example.o example.c -D FREEGLUT_STATIC -I"C:\MinGW\include\GL"
gcc -o example.exe example.o -L"C:\MinGW\lib" -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows