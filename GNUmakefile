SOURCES    := $(wildcard source/*.cpp)
HEADERS    := $(wildcard api/*.h source/*.hpp)
OBJECTS    := $(patsubst source/%.cpp,build/%.o,$(SOURCES))
DEPS       := $(OBJECTS:.o=.d)

CXX        ?= clang++
DEFS       ?= -D_DEBUG
CXXFLAGS   := -Wall -Werror -std=c++23 $(shell llvm-config --cxxflags) $(DEFS)\
	      -I./external/ -fexceptions
LDFLAGS    := $(shell llvm-config --cxxflags --ldflags --libs) -L./external/
TARGET     ?= vireo
PREFIX     ?= /usr/local

.PHONY: all clean install dist format

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@printf '\033[34m[i]\033[0m Linking %s from %s\n' $@ "$^"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

build/%.o: source/%.cpp | build
	@printf '\033[32m[i]\033[0m Compiling %s -> %s\n' $< $@
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

build:
	mkdir -p build

install: $(TARGET)
	@printf '\033[34m[i]\033[0m Installing $(TARGET) to $(PREFIX)\n'
	install -d $(PREFIX)/bin
	install -m 755 $(TARGET) $(PREFIX)/bin

	@printf '\033[34m[i]\033[0m Installing headers to $(PREFIX)/include/vireo\n'
	install -d $(PREFIX)/include/vireo
	install -m 644 api/*.h $(PREFIX)/include/vireo

	@printf '\033[34m[i]\033[0m Installing pkg-config file\n'
	install -d $(PREFIX)/lib/pkgconfig
	install -m 644 vireo.pc $(PREFIX)/lib/pkgconfig

deinstall:
	@printf '\033[31m[i]\033[0m Deinstalling $(TARGET) from $(PREFIX)...\n'
	-rm -f $(PREFIX)/bin/$(TARGET)
	-rm -rf $(PREFIX)/include/vireo
	-rm -f $(PREFIX)/lib/pkgconfig/vireo.pc

clean:
	@printf '\033[31m[i]\033[0m Cleaning build artifacts\n'
	rm -rf build $(TARGET)

	rm -rf html
	rm -rf latex

doxy:
	doxygen

dist: clean
	@printf '\033[36m[i]\033[0m Creating source archive\n'
	tar czf $(TARGET)-src.tar.gz source api Makefile vireo.pc

format:
	@echo "Formatting C/C++ sources and headers..."
	clang-format -i $(SOURCES) $(HEADERS)

-include $(DEPS)

# vim: set ts=2 sw=2 sts=2 noet tw=80:
