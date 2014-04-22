SOURCES=MathDLL.cpp 
OBJECTS=$(SOURCES:.cpp=.obj)
LIBS=$(SOURCES:.cpp=.lib)
EXPS=$(SOURCES:.cpp=.exp)
EXECUTABLE=MathDLL.dll
	
$(EXECUTABLE): MathDLL.cpp MathDLL.h
	cl /LD $(SOURCES) /link /DLL /out:$(EXECUTABLE)
	
clean:
	del $(OBJECTS) $(EXECUTABLE) $(LIBS) $(EXPS)
	
all: clean $(EXECUTABLE)
