all:
	g++ main.cpp -o battle.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

static:
	g++ main.cpp -DSFML_STATIC -o battle.exe -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lfreetype -ljpeg -lwinmm -lgdi32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg

