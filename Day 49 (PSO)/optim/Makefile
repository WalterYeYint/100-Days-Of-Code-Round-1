
# core compiling options

CC  = gcc
CXX = g++
FC  = gfortran

CXX_STD = -std=c++11
OPT_FLAGS = -Wall -fPIC -O3 -march=native -ffp-contract=fast -flto -DNDEBUG -DARMA_NO_DEBUG -fopenmp

ARMA_INCLUDE_PATH = /usr/include

# install location
INSTALL_PATH=/usr/local

# source directories
SDIR = .
OPTIM_DIR = $(SDIR)
OPTIM_SRC_DIR = $(SDIR)/src
OPTIM_HEADER_DIR = $(SDIR)/include

# shared library name and flags
SHLIB = liboptim.so
SHLIB_FLAGS = $(CXX_STD) -fPIC -O3 -march=native -ffp-contract=fast -flto -DNDEBUG -DARMA_NO_DEBUG -fopenmp -fPIC -shared -L/usr/local/lib -Wl,-Bsymbolic-functions -Wl,-z,relro

# general flags
CXXFLAGS = $(CXX_STD) $(OPT_FLAGS) -I$(ARMA_INCLUDE_PATH) -I$(OPTIM_HEADER_DIR)
LIBS= -lblas -llapack

# core Optim files

SOURCES_OPTIM_LS= $(OPTIM_SRC_DIR)/line_search/more_thuente.cpp
OBJECTS_OPTIM_LS= $(SOURCES_OPTIM_LS:.cpp=.o)

SOURCES_OPTIM_UNCONSTR := $(shell find $(OPTIM_SRC_DIR)/unconstrained -name '*.cpp')
OBJECTS_OPTIM_UNCONSTR := $(SOURCES_OPTIM_UNCONSTR:%.cpp=%.o)

SOURCES_OPTIM_CONSTR= $(OPTIM_SRC_DIR)/constrained/sumt.cpp
OBJECTS_OPTIM_CONSTR= $(SOURCES_OPTIM_CONSTR:.cpp=.o)

SOURCES_OPTIM_ZEROS= $(OPTIM_SRC_DIR)/zeros/broyden.cpp
OBJECTS_OPTIM_ZEROS= $(SOURCES_OPTIM_ZEROS:.cpp=.o)

OBJECTS_OPTIM= $(OBJECTS_OPTIM_LS) $(OBJECTS_OPTIM_UNCONSTR) $(OBJECTS_OPTIM_CONSTR) $(OBJECTS_OPTIM_ZEROS)

all: $(OPTIM_DIR)/$(SHLIB) $(OBJECTS_OPTIM)

# core Optim files
$(OPTIM_SRC_DIR)/misc/%.o: $(OPTIM_SRC_DIR)/misc/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OPTIM_SRC_DIR)/line_search/%.o: $(OPTIM_SRC_DIR)/line_search/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OPTIM_SRC_DIR)/unconstrained/%.o: $(OPTIM_SRC_DIR)/unconstrained/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OPTIM_SRC_DIR)/constrained/%.o: $(OPTIM_SRC_DIR)/constrained/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OPTIM_SRC_DIR)/generic/%.o: $(OPTIM_SRC_DIR)/generic/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OPTIM_SRC_DIR)/zeros/%.o: $(OPTIM_SRC_DIR)/zeros/%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@


# shared library
$(OPTIM_DIR)/$(SHLIB): $(OBJECTS_OPTIM)
	$(CXX) $(SHLIB_FLAGS) -o $@ $^ $(LIBS)

# cleanup and install
.PHONY: clean
clean:
	@rm -f *.so ./tests/*/*.test ./tests/*/*.o $(OPTIM_SRC_DIR)/*/*.o ./tests/*/*.tmp $(OPTIM_SRC_DIR)/*/*.tmp \
            $(OPTIM_SRC_DIR)/*/*.gcov $(OPTIM_SRC_DIR)/*/*.gcno $(OPTIM_SRC_DIR)/*/*.gcda $(OPTIM_SRC_DIR)/*/*.dSYM \
            $(OPTIM_SRC_DIR)/*/*/*.o $(OPTIM_SRC_DIR)/*/*/*.gcov $(OPTIM_SRC_DIR)/*/*/*.gcno $(OPTIM_SRC_DIR)/*/*/*.gcda $(OPTIM_SRC_DIR)/*/*/*.dSYM

.PHONY: vclean
vclean:
	@rm -f *.so ./tests/*/*.test ./tests/*/*.o $(OPTIM_SRC_DIR)/*/*.o $(OPTIM_SRC_DIR)/*/*/*.o
	@rm -rf ./include/armadillo*

.PHONY: install
install: $(SHLIB)
	@cp $(OPTIM_DIR)/$(SHLIB) $(INSTALL_PATH)/lib/$(SHLIB)
	@mkdir -p $(INSTALL_PATH)/include/optim
	@cp -r $(OPTIM_DIR)/include/* $(INSTALL_PATH)/include/optim
