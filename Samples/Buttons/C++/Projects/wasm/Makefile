# GNU Make project for 'Samples.Buttons'

# Parallel builds can be enabled using the environment variable MAKEFLAGS (eg: MAKEFLAGS="-j 4")
# For parallel execution in Windows, Make 4.0 or better is required

include ../../../../../Config/Common.wasm.makeprops
include ../../../../../Config/Debug/Debug.wasm.makeprops
include ../../../../../Config/Profile/Profile.wasm.makeprops
include ../../../../../Config/Release/Release.wasm.makeprops

CC = emcc
CXX = em++

SHELLTYPE = msdos
ifeq (, $(ComSpec)$(COMSPEC))
  SHELLTYPE = posix
endif
ifeq (/bin, $(findstring /bin, $(SHELL)))
  SHELLTYPE = posix
endif
ifeq (/bin, $(findstring /bin, $(MAKESHELL)))
  SHELLTYPE = posix
endif

ifeq (posix, $(SHELLTYPE))
  DEVNUL = /dev/null
  WHICH = which
  MKDIR = mkdir -p "$(1)"
  BIN2H = ../../../../../Tools/Bin2h/bin2h.py
  CP = cp "$(1)" "$(2)"
  MV = mv "$(1)" "$(2)"
  RM = rm -f "$(1)"
  RMTREE = rm -rf "$(1)"
  FIXSLASHES = 
else
  DEVNUL = NUL
  WHICH = where
  MKDIR = mkdir "$(subst /,\,$(1))" 2> nul || exit 0
  BIN2H = ..\..\..\..\..\Tools\Bin2h\bin2h.exe
  CP = copy /Y "$(subst /,\,$(1))" "$(subst /,\,$(2))" > nul
  MV = move /Y "$(subst /,\,$(1))" "$(subst /,\,$(2))" > nul
  RM = del /Q "$(subst /,\,$(1))" 2> nul || exit 0
  RMTREE = rmdir /S /Q "$(subst /,\,$(1))" 2> nul || exit 0
  SED = ..\..\..\..\..\Tools\sed\sed.exe
  FIXSLASHES = $(SED) -i "s/\(\S\)\\\(\S\)/\1\/\2/g" "$(1)"
endif

ifeq (, $(shell ${WHICH} $(CC) 2> $(DEVNUL) ))
$(error $(CC) not found in PATH)
endif

ifeq (, $(shell ${WHICH} $(CXX) 2> $(DEVNUL) ))
$(error $(CXX) not found in PATH)
endif

ifeq ($(V), 1)
  Q =
else
  Q = @
endif

ifndef CONFIG
  CONFIG = Release
endif

ifeq ($(CONFIG), Debug)
  TARGET_DIR = ../../../../../../Bin/wasm
  TARGET = ../../../../../../Bin/wasm/Samples.Buttons.bc
  TARGET_HTML = ../../../../../../Bin/wasm/Samples.Buttons.html
  INTERMEDIATE = build/Debug
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../../../../Include -I../../../../App/ApplicationLauncher/Include -I../../../../App/DisplayLauncher/Include -I../../../../App/Display/Include -I../../../../App/Interactivity/Include -I../../../../App/Launcher/Include -I../../../../App/Providers/Include -Ibuild/Debug
  DEFINES = -DNS_BUILD -DNS_CONFIG=Debug -DNS_VERSION=3.0.4 -DNS_APP_FRAMEWORK -DNS_LICENSE -DNS_STATIC_LIBRARY -DNS_DEBUG -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=1
  CFLAGS = $(CFLAGS_DEBUG)
  CXXFLAGS = $(CXXFLAGS_DEBUG)
  LDFLAGS = $(LDFLAGS_DEBUG)
else ifeq ($(CONFIG), Profile)
  TARGET_DIR = ../../../../../../Bin/wasm
  TARGET = ../../../../../../Bin/wasm/Samples.Buttons.bc
  TARGET_HTML = ../../../../../../Bin/wasm/Samples.Buttons.html
  INTERMEDIATE = build/Profile
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../../../../Include -I../../../../App/ApplicationLauncher/Include -I../../../../App/DisplayLauncher/Include -I../../../../App/Display/Include -I../../../../App/Interactivity/Include -I../../../../App/Launcher/Include -I../../../../App/Providers/Include -Ibuild/Profile
  DEFINES = -DNS_BUILD -DNS_CONFIG=Profile -DNS_VERSION=3.0.4 -DNS_APP_FRAMEWORK -DNS_LICENSE -DNS_STATIC_LIBRARY -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=2
  CFLAGS = $(CFLAGS_PROFILE)
  CXXFLAGS = $(CXXFLAGS_PROFILE)
  LDFLAGS = $(LDFLAGS_PROFILE)
else ifeq ($(CONFIG), Release)
  TARGET_DIR = ../../../../../../Bin/wasm
  TARGET = ../../../../../../Bin/wasm/Samples.Buttons.bc
  TARGET_HTML = ../../../../../../Bin/wasm/Samples.Buttons.html
  INTERMEDIATE = build/Release
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../../../../Include -I../../../../App/ApplicationLauncher/Include -I../../../../App/DisplayLauncher/Include -I../../../../App/Display/Include -I../../../../App/Interactivity/Include -I../../../../App/Launcher/Include -I../../../../App/Providers/Include -Ibuild/Release
  DEFINES = -DNS_BUILD -DNS_CONFIG=Release -DNS_VERSION=3.0.4 -DNS_APP_FRAMEWORK -DNS_LICENSE -DNS_STATIC_LIBRARY
  CFLAGS = $(CFLAGS_RELEASE)
  CXXFLAGS = $(CXXFLAGS_RELEASE)
  LDFLAGS = $(LDFLAGS_RELEASE)
else
  $(error Invalid configuration '$(CONFIG)')
endif

PCH =
PCHFLAGS =
DATA = $(INTERMEDIATE)/App.xaml.bin.h $(INTERMEDIATE)/Resources.xaml.bin.h $(INTERMEDIATE)/MainWindow.xaml.bin.h $(INTERMEDIATE)/AudioSlide.mp3.bin.h $(INTERMEDIATE)/AudioClick.mp3.bin.h $(INTERMEDIATE)/Aero\ Matics\ Regular.ttf.bin.h

.SUFFIXES:
.DELETE_ON_ERROR:
.PHONY: all prebuild data clean

all: prebuild $(TARGET_HTML)

prebuild:
	@echo ==== [Samples.Buttons] Building '$(CONFIG)' configuration ====

data: $(DATA)

$(INTERMEDIATE):
	$(Q)$(call MKDIR,$(INTERMEDIATE))

$(TARGET_DIR):
	$(Q)$(call MKDIR,$(TARGET_DIR))

$(INTERMEDIATE)/%.o: ../../../../Samples/Buttons/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Samples/Buttons] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -c -MMD -MF $(basename $@).d.tmp -MP -o $@ $< && $(call MV,$(basename $@).d.tmp,$(basename $@).d)

	$(Q)$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../../Samples/Buttons/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Samples/Buttons] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -c -MMD -MF $(basename $@).d.tmp -MP -o $@ $< && $(call MV,$(basename $@).d.tmp,$(basename $@).d)

	$(Q)$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/App.xaml.bin.h: ../../../../Samples/Buttons/Data/App.xaml | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/App.xaml" > "$(INTERMEDIATE)/App.xaml.bin.h" 

$(INTERMEDIATE)/Resources.xaml.bin.h: ../../../../Samples/Buttons/Data/Resources.xaml | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/Resources.xaml" > "$(INTERMEDIATE)/Resources.xaml.bin.h" 

$(INTERMEDIATE)/MainWindow.xaml.bin.h: ../../../../Samples/Buttons/Data/MainWindow.xaml | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/MainWindow.xaml" > "$(INTERMEDIATE)/MainWindow.xaml.bin.h" 

$(INTERMEDIATE)/AudioSlide.mp3.bin.h: ../../../../Samples/Buttons/Data/AudioSlide.mp3 | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/AudioSlide.mp3" > "$(INTERMEDIATE)/AudioSlide.mp3.bin.h" 

$(INTERMEDIATE)/AudioClick.mp3.bin.h: ../../../../Samples/Buttons/Data/AudioClick.mp3 | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/AudioClick.mp3" > "$(INTERMEDIATE)/AudioClick.mp3.bin.h" 

$(INTERMEDIATE)/Aero\ Matics\ Regular.ttf.bin.h: ../../../../Samples/Buttons/Data/Aero\ Matics\ Regular.ttf | $(INTERMEDIATE)
	@echo [BIN] [Samples/Buttons] $(notdir $<)
	$(Q)$(BIN2H) "../../../../Samples/Buttons/Data/Aero Matics Regular.ttf" > "$(INTERMEDIATE)/Aero Matics Regular.ttf.bin.h" 

$(TARGET): $(LIBS_DEPS) $(INTERMEDIATE)/App.xaml.o $(INTERMEDIATE)/Main.o $(INTERMEDIATE)/MainWindow.xaml.o $(INTERMEDIATE)/ViewModel.o | $(TARGET_DIR)
	@echo [LD] $(notdir $@)
	+$(Q)$(CXX) $(LDFLAGS) -r $(LIB_DIRS) -o $(TARGET) @$(CONFIG).rsp $(LIBS)

$(TARGET_HTML): $(TARGET) ../../../../../../Bin/wasm/Noesis.bc ../../../../../../Bin/wasm/NoesisApp.bc
	@echo [HTML] $(notdir $@)
	$(Q)$(CC) $(LDFLAGS) $(TARGET) ../../../../../../Bin/wasm/Noesis.bc ../../../../../../Bin/wasm/NoesisApp.bc -o $(basename $(TARGET)).html --shell-file shell.html

-include $(INTERMEDIATE)/App.xaml.d $(INTERMEDIATE)/Main.d $(INTERMEDIATE)/MainWindow.xaml.d $(INTERMEDIATE)/ViewModel.d

clean:
	@echo ==== [Samples.Buttons] Cleaning '$(CONFIG)' configuration ====
	$(Q)$(call RMTREE,$(INTERMEDIATE))
	$(Q)$(call RM,$(TARGET))
	$(Q)$(call RM,$(basename $(TARGET)).js)
	$(Q)$(call RM,$(basename $(TARGET)).wasm)
	$(Q)$(call RM,$(basename $(TARGET)).wast)
	$(Q)$(call RM,$(basename $(TARGET)).html)
