SOURCES=MathDLL.cpp 
OBJECTS=$(SOURCES:.cpp=.obj)
LIBS=$(SOURCES:.cpp=.lib)
EXPS=$(SOURCES:.cpp=.exp)
EXECUTABLE=MathDLL.exe
	
$(EXECUTABLE): $(OBJECTS) 
				link /DLL /out:$(EXECUTABLE) $(OBJECTS)

MathDLL.obj: MathDLL.cpp MathDLL.h
				cl /c /EHsc MathDLL.cpp
	
clean:
	del $(OBJECTS) $(EXECUTABLE) $(LIBS) $(EXPS)
	
all: clean $(EXECUTABLE)
