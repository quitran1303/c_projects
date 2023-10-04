#Set commands and target extension for different environment (Windows, Unix)
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),)
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=exe
else #Unix base
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean
.PHONY: test
.PHONY: compile
.PHONY: install

PATH_UNITY = test/unity/src/
PATH_SRC = src/
PATH_TEST = test/
PATH_BUILD = build/
PATH_DEPENDS = build/depends/
PATH_OBJS = build/objs/
PATH_RESULTS = build/results/

_OBJS = main.o calc.o
OBJS = $(patsubst %,$(PATH_OBJS)%,$(_OBJS))
BUILD_PATHS = $(PATH_BUILD) $(PATH_DEPENDS) $(PATH_OBJS) $(PATH_RESULTS)
SRC_TEST = $(wildcard $(PATH_TEST)*.c)
COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF

CFLAGS=-I. -I$(PATH_UNITY) -I$(PATH_SRC) -DTEST

#For getting the test result in text files
RESULTS = $(patsubst $(PATH_TEST)Test%.c,$(PATH_RESULTS)Test%.txt,$(SRC_TEST) )
PASSED = `grep -s PASS $(PATH_RESULTS)*.txt`
FAIL = `grep -s FAIL $(PATH_RESULTS)*.txt`
IGNORE = `grep -s IGNORE $(PATH_RESULTS)*.txt`
LAST_LINES = `tail -n 3 $(PATH_RESULTS)*.txt`

all: test compile install

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "$(LAST_LINES)"

$(PATH_RESULTS)%.txt: $(PATH_BUILD)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

#Link all test file
$(PATH_BUILD)Test%.$(TARGET_EXTENSION): $(PATH_OBJS)Test%.o $(PATH_OBJS)%.o $(PATH_OBJS)unity.o
	$(LINK) -o $@ $^

$(PATH_OBJS)%.o:: $(PATH_TEST)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_SRC)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_OBJS)%.o:: $(PATH_UNITY)%.c $(PATH_UNITY)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATH_DEPENDS)%.d:: $(PATH_TEST)%.c
	$(DEPEND) $@ $<

$(PATH_BUILD):
	$(MKDIR) $(PATH_BUILD)

$(PATH_DEPENDS):
	$(MKDIR) $(PATH_DEPENDS)

$(PATH_OBJS):
	$(MKDIR) $(PATH_OBJS)

$(PATH_RESULTS):
	$(MKDIR) $(PATH_RESULTS)

compile: $(OBJS)

install: $(OBJS)
	$(LINK) -o calc.$(TARGET_EXTENSION) $(OBJS)

clean:
	$(CLEANUP) $(PATH_OBJS)*.o
	$(CLEANUP) $(PATH_BUILD)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATH_RESULTS)*.txt
	$(CLEANUP) calc.$(TARGET_EXTENSION)

.PRECIOUS: $(PATH_BUILD)Test%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATH_DEPENDS)%.d
.PRECIOUS: $(PATH_OBJS)%.o
.PRECIOUS: $(PATH_RESULTS)%.txt
