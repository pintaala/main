SOURCES=Pinta_ala_app.cpp
OBJECTS=$(SOURCES:.cpp=.obj)
EXECUTABLE=calc.exe

$(EXECUTABLE): $(OBJECTS)
				link /DLL /out:$(EXECUTABLE) $(OBJECTS)

Pinta_ala_app.cpp.obj: Pinta_ala_app.cpp
				cl /c /EHsc Pinta_ala_app.cpp.cpp

clean:
	del $(OBJECTS) $(EXECUTABLE)

all: clean $(EXECUTABLE)
