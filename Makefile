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
CompileCommand = javac
SpecifyDirFlag = -d
RunCommand     = java
GoToDirFlag    = --class-path



# our directories/subdirectories/files variables
SourceDir       = ./src
OutputDir       = ./out
SourceFiles     = $(wildcard $(SourceDir)/*.java)
ExpectedOutputs = $(patsubst $(SourceDir)/%, $(OutputDir)/%, $(patsubst %.java, %.class, $(SourceFiles)))
FinalExeName    = Main



# our escapes/strings variables
ESCAPE_RESET     = \e[0m
ESCAPE_YELLOW    = \e[33m
ESCAPE_B_RED     = \e[1;31m
ESCAPE_B_GREEN   = \e[1;32m
ESCAPE_B_YELLOW  = \e[1;33m
ESCAPE_B_BLUE    = \e[1;34m
ESCAPE_B_MAGENTA = \e[1;35m
ESCAPE_I         = \e[3m


# all recipe >>> will just print the help message
all:
	@printf "\n"                                                                                                  ;
	@printf " $(ESCAPE_B_MAGENTA)◆$(ESCAPE_RESET) Are you trying to use $(ESCAPE_B_BLUE)Kojamp$(ESCAPE_RESET)?\n" ;
	@printf " │\n"                                                                                                ;
	@printf " └─ $(ESCAPE_B_YELLOW)You can type:$(ESCAPE_RESET)\n"                                                ;
	@printf " \t└ $(ESCAPE_YELLOW)make build:$(ESCAPE_RESET) will build the outputs\n"                            ;
	@printf " \t└ $(ESCAPE_YELLOW)make run:$(ESCAPE_RESET)   will execute the outputs\n"                          ;
	@printf "\n"                                                                                                  ;



# build recipe >>> will generate the output exe (bytecode)
build:
	@printf "\n"                                                                                                      ;
	@for outFile in $(ExpectedOutputs)                                                                                ; do   \
		if [ -f $$outFile ]                                                                                             ; then \
			printf " $(ESCAPE_B_RED)error:$(ESCAPE_RESET) $(ESCAPE_I)<$$outFile>$(ESCAPE_RESET) already exists!"          ;      \
			printf "\n\n"                                                                                                 ;      \
			printf " If you want to rebuild the entire project, try\n\n"                                                  ;      \
			printf " \t$(ESCAPE_YELLOW)1.$(ESCAPE_RESET) make clean\n"                                                    ;      \
			printf " \t$(ESCAPE_YELLOW)2.$(ESCAPE_RESET) make build\n"                                                    ;      \
			printf "\n"                                                                                                   ;      \
			exit 1                                                                                                        ;      \
		fi                                                                                                              ;      \
	done                                                                                                              ;
	@if [ ! -d $(OutputDir) ]                                                                                         ; then \
		mkdir $(OutputDir)                                                                                              ;      \
	fi                                                                                                                ;
	@printf " $(ESCAPE_B_GREEN)Building$(ESCAPE_RESET) outputs... $(ESCAPE_I)(this can take a while)$(ESCAPE_RESET)\n";
	@$(CompileCommand) $(SourceFiles) $(SpecifyDirFlag) $(OutputDir)                                                  ;
	@printf "\n"                                                                                                      ;
	@printf " The program $(ESCAPE_B_GREEN)was built successfully!$(ESCAPE_RESET)\n"                                  ;
	@printf "\n"                                                                                                      ;



# clean recipe >>> will remove the output dir
clean:
	@printf "\n"                                                            ;
	@if [ ! -d $(OutputDir) ]                                               ; then \
  	printf " Output dir $(ESCAPE_B_RED)doesn't exists$(ESCAPE_RESET)!\n"  ;      \
		printf " $(ESCAPE_B_GREEN)Nothing$(ESCAPE_RESET) to remove...\n"      ;      \
	else                                                                           \
		rm -r $(OutputDir)                                                    ;      \
		printf " Output dir $(ESCAPE_B_RED)has been removed$(ESCAPE_RESET)!\n";      \
	fi                                                                      ;
	@printf "\n"                                                            ;



# run recipe >>> will run the generated bytecode
run: $(ExpectedOutputs) $(OutputDir)/$(FinalExeName).class
	@printf "\n"                                                                                                           ;
	@printf "The program is $(ESCAPE_B_GREEN)ready to run: $(ESCAPE_B_YELLOW)$(OutputDir)/$(FinalExeName)$(ESCAPE_RESET)\n";
	@printf "\n"                                                                                                           ;
	@$(RunCommand) $(GoToDirFlag) $(OutputDir) $(FinalExeName)                                                             ;
	@printf "\n"                                                                                                           ;
