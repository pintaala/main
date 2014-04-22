SOURCES=Pinta_ala_app.cpp
OBJECTS=$(SOURCES:.cpp=.obj)
EXECUTABLE=calc.exe

$(EXECUTABLE): $(OBJECTS)
	link /out:$(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): Pinta_ala_app.cpp
	cl /c /EHsc Pinta_ala_app.cpp

clean:
	del $(OBJECTS) $(EXECUTABLE)

all: clean $(EXECUTABLE)
