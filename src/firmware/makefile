.PHONY: all clean

# Compiler
CC = sdcc

#Platform
PLATFORM = mcs51

# Target name
PNAME = main

# Select target controller:
TARGET_CONTROLLER = BBSHD
#TARGET_CONTROLLER = BBS02


XRAM_SIZE = 1792
ifeq ($(TARGET_CONTROLLER), BBSHD)
	XRAM_SIZE = 3840
endif

# External libraries
IDIR = 
SDIR = 

MAINSRC = main.c

EXTRASRCS = \
	adc.c \
	app.c \
	battery.c \
	cfgstore.c \
	eeprom.c \
	eventlog.c \
	extcom.c \
	timers.c \
	lights.c \
	motor.c \
	uart.c \
	system.c \
	throttle.c \
	watchdog.c \
	sensors.c
	
HEADERS = \
	adc.h \
	app.h \
	battery.h \
	cfgstore.h \
	eventlog.h \
	eeprom.h \
	extcom.h \
	timers.h \
	lights.h \
	motor.h \
	uart.h \
	system.h \
	throttle.h \
	util.h \
	version.h \
	watchdog.h \
	sensors.h \
	pins.h

# The list of .rel files can be derived from the list of their source files
RELS = $(EXTRASRCS:.c=.rel)

INCLUDES = -I$(IDIR) -I. -I../
CFLAGS   = -m$(PLATFORM) --model-large --xram-size $(XRAM_SIZE) -Ddouble=float --std-c99 -D$(TARGET_CONTROLLER)
ELF_FLAGS = 
LIBS     = 

all: $(PNAME) hex

$(PNAME): $(MAINSRC) $(RELS)
	$(CC) $(INCLUDES) $(CFLAGS) $(ELF_FLAGS) $(LIBS) $(MAINSRC) $(RELS)

# Build .rel file from .c file
%.rel: %.c $(HEADERS)
	$(CC) -c $(INCLUDES) $(CFLAGS) $(ELF_FLAGS) $(LIBS) $<

# Suffixes appearing in suffix rules we care about.
# Necessary because .rel is not one of the standard suffixes.
.SUFFIXES: .c .rel

hex:
	@cmd /C tohex.bat
	
clean:
	@cmd /C clean.bat
	@echo "Clean Finished"
