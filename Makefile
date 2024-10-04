#--------------------------------------------------------------------
# Kojamp Man - Makefile
#
#   This is the Kojamp Man Makefile!
#
#   Here, we'll be building cool stuff about the program, so, that
#   can bu runned later...
#
#   All `Copy (c)` relevant content was already placed ad README.md
#   file
#--------------------------------------------------------------------

# our command/flag variables
CompileCCommand   = gcc
CompileCommand    = javac
SpecifyDirFlag    = -d
SpecifyOutBinFlag = -o
RunCommand        = java
GoToDirFlag       = --class-path



# our directories/subdirectories/files variables
SourceDir        = ./src
OutputDir        = ./out
SetupDir         = ./setup
BinDir           = ./bin
SourceFiles      = $(wildcard $(SourceDir)/*.java)
ExpectedOutputs  = $(patsubst $(SourceDir)/%, $(OutputDir)/%, $(patsubst %.java, %.class, $(SourceFiles)))
CSource          = $(SetupDir)/kojamp.c
FinalExe         = $(BinDir)/kojamp
SourceCollection = $(foreach sfile, $(wildcard $(SetupDir)/*.c) $(wildcard $(SetupDir)/*.h), $(lastword $(subst /, , $(sfile))))
FinalExeName     = Main



# our escapes/strings variables
ESCAPE_RESET     = \e[0m
ESCAPE_YELLOW    = \e[0;33m
ESCAPE_B_RED     = \e[1;31m
ESCAPE_B_GREEN   = \e[1;32m
ESCAPE_B_YELLOW  = \e[1;33m
ESCAPE_B_BLUE    = \e[1;34m
ESCAPE_B_MAGENTA = \e[1;35m
ESCAPE_I         = \e[3m



# repository URL
RepoURL = https://github.com/nasccped/kojamp-man



# all recipe >>> will just print the help message
all:
	@printf "\n"                                                                                                           ;
	@printf " $(ESCAPE_B_MAGENTA)◆ SETUP:$(ESCAPE_RESET) Are you trying to use $(ESCAPE_B_MAGENTA)Kojamp$(ESCAPE_RESET)?\n";
	@printf " │\n"                                                                                                         ;
	@printf " └─ $(ESCAPE_B_YELLOW)You can type:$(ESCAPE_RESET)\n"                                                         ;
	@printf " \t└ $(ESCAPE_B_BLUE)make binary:$(ESCAPE_RESET) will build the binaries\n"                                   ;
	@printf "\n"                                                                                                           ;



binary:
	@printf "\n"                                                                                                                              ;
	@if [ -x $(FinalExe) ]                                                                                                                    ; then \
		printf " $(ESCAPE_B_RED)◆ ERROR:$(ESCAPE_RESET) Binary file already exists $(ESCAPE_I)< $(FinalExe) >$(ESCAPE_RESET)\n"                 ;      \
		printf " │\n"                                                                                                                           ;      \
		printf " └─ $(ESCAPE_B_YELLOW)You can try:$(ESCAPE_RESET)\n"                                                                            ;      \
		printf " \t└ $(ESCAPE_B_BLUE)1. $(ESCAPE_YELLOW)make clean:$(ESCAPE_RESET)  will delete the binary folder\n"                            ;      \
		printf " \t└ $(ESCAPE_B_BLUE)2. $(ESCAPE_YELLOW)make binary:$(ESCAPE_RESET) will build the binaries $(ESCAPE_I)(again)$(ESCAPE_RESET)\n";      \
	elif [ ! -f $(CSource) ]                                                                                                                  ; then \
		printf " $(ESCAPE_B_RED)◆ ERROR:$(ESCAPE_RESET) C file $(ESCAPE_I)< $(CSource) >$(ESCAPE_RESET) was not found!\n"                       ;      \
		printf " │\n"                                                                                                                           ;      \
		printf " └─ $(ESCAPE_B_YELLOW)Check how to fix$(ESCAPE_RESET) at $(ESCAPE_I)$(RepoURL)$(ESCAPE_RESET)\n"                                ;      \
	else                                                                                                                                             \
		printf " $(ESCAPE_B_GREEN)◆ SUCCESS:$(ESCAPE_RESET) C file was found!\n"                                                                ;      \
		printf " │\n"                                                                                                                           ;      \
		printf " └─ $(ESCAPE_B_YELLOW)Ready to be compiled:$(ESCAPE_RESET)\n"                                                                   ;      \
		for file in $(SourceCollection)                                                                                                         ; do   \
			printf " │\t└ $(ESCAPE_B_BLUE)$$file$(ESCAPE_RESET)\n"                                                                                ;      \
		done                                                                                                                                    ;      \
		printf " │\n"                                                                                                                           ;      \
		printf " └ $(ESCAPE_B_YELLOW)Compilation status:$(ESCAPE_RESET)\n\n"                                                                    ;      \
		if [ ! -d $(BinDir) ]                                                                                                                   ; then \
			mkdir $(BinDir)                                                                                                                       ;      \
		fi                                                                                                                                      ;      \
		$(CompileCCommand) $(CSource) -o $(FinalExe)                                                                                            ;      \
		printf "\n $(ESCAPE_B_YELLOW)◆ BINARY FILE:$(ESCAPE_RESET) "                                                                            ;      \
		if [ -x $(FinalExe) ]                                                                                                                   ; then \
			printf "$(ESCAPE_B_GREEN)was generated$(ESCAPE_RESET)!\n"                                                                             ;      \
		else                                                                                                                                           \
			printf "$(ESCAPE_B_RED)was not generated$(ESCAPE_RESET)!\n"                                                                           ;      \
		fi                                                                                                                                      ;      \
	fi                                                                                                                                        ;
	@printf "\n"                                                                                                                              ;



# clean recipe >>> will remove the binary dir
clean:
	@printf "\n"                                                                                                       ;
	@if [ ! -d $(BinDir) ]                                                                                             ; then \
		printf " $(ESCAPE_B_RED)◆ ERROR:$(ESCAPE_RESET) Binary dir doesn't exists!\n"                                    ;      \
		printf " │\n"                                                                                                    ;      \
		printf " └─ $(ESCAPE_B_YELLOW)status:$(ESCAPE_RESET) $(ESCAPE_B_GREEN)nothing$(ESCAPE_RESET) to remove...\n"     ;      \
	else                                                                                                                      \
		rm -r $(BinDir)                                                                                                  ;      \
		printf " $(ESCAPE_B_GREEN)◆ SUCCESS:$(ESCAPE_RESET) Binary dir was found!\n"                                     ;      \
		printf " │\n"                                                                                                    ;      \
		printf " └─ $(ESCAPE_B_YELLOW)status:$(ESCAPE_RESET) dir has been $(ESCAPE_B_GREEN)removed$(ESCAPE_RESET)...\n"  ;      \
	fi                                                                                                                 ;
	@printf "\n"                                                                                                       ;
