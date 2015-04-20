OBJECTS = main.o asignaturas.o persona.o generarpersona.o


main: $(OBJECTS)
	g++ -o main  $(OBJECTS)


main.o: main.cpp asignaturas.hpp listaOrdenadaDoblementeEnlazada.hpp nodoDoblementeenlazado.hpp
	g++ -c  main.cpp

asignaturas.o: asignaturas.cpp asignaturas.hpp listaOrdenadaDoblementeEnlazada.hpp nodoDoblementeenlazado.hpp
	g++ -c  asignaturas.cpp

persona.o: persona.cpp persona.hpp
	g++ -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp
	g++ -c generarpersona.cpp

clean:
	rm -f  $(OBJECTS) *~
