# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 23:26:34 by mbouthai          #+#    #+#              #
#    Updated: 2023/08/05 23:29:26 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Headers/Includes

HEADERS_DIR	:= .

# Sources

SRCS_DIR	:= .

SOURCES	= AForm.cpp Bureaucrat.cpp \
	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp Intern.cpp main.cpp
SOURCES	:= $(addprefix $(SRCS_DIR)/,$(SOURCES))

# Objects/Output files

OBJS_DIR	= obj
OBJECTS	:= $(patsubst $(SRCS_DIR)/%,$(OBJS_DIR)/%.o,$(SOURCES))

# Dependencies

DEPS_DIR	= dep
DEPENDENCIES	:= $(patsubst %,%.d,$(addprefix $(DEPS_DIR)/,$(notdir $(SOURCES))))

DIRS	=
DIRS	:= $(addprefix $(OBJS_DIR)/,$(DIRS))

# Colors

BOLD	:=\033[1m

RESET	:=\033[0m

RED		:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

define	colorize =
	@echo "\n$(1)$(2)$(RESET)\n"
endef

# Configuration

CXX	:= c++

CPPFLAGS	:= -Wall -Werror -Wextra -std=c++98 -I$(HEADERS_DIR)/ -fsanitize=address

LDFLAGS	:= -fsanitize=address

CLEAN_DIR	:= rm -fd

CLEAN_FILES	:= rm -f

NAME	= main

define PROJECT_HEADER

  _____       _                      
 |_   _|     | |                     
   | |  _ __ | |_ ___ _ __ _ __  ___ 
   | | | '_ \| __/ _ \ '__| '_ \/ __|
  _| |_| | | | ||  __/ |  | | | \__ \\
 |_____|_| |_|\__\___|_|  |_| |_|___/
                                     
                                     
endef
export PROJECT_HEADER

all: $(NAME)

debug: fclean
debug: CPPFLAGS += -g

debug: all

$(NAME): $(OBJECTS)
	$(call colorize,$(GREEN),Building Project...)
	$(CXX) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)
	$(call colorize,$(BOLD),$$PROJECT_HEADER)

$(OBJS_DIR):
	$(call colorize,$(GREEN),Creating Objects Directory...)
	-mkdir $@ $(DIRS)

$(DEPS_DIR):
	$(call colorize,$(GREEN),Creating Dependencies Directory...)
	-mkdir $@

compile:
	$(call colorize,$(GREEN),Compiling...)

$(OBJECTS): | $(OBJS_DIR)

$(OBJECTS): | $(DEPS_DIR)

$(OBJECTS): | compile

$(OBJECTS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%
	$(CXX) $(CPPFLAGS) -MMD -MP -MF $(addprefix $(DEPS_DIR)/,$(notdir $(<:%=%.d))) -c $< -o $@

cleanobjs:
	$(call colorize,$(GREEN),Cleaning Object Files...)
	-$(CLEAN_FILES) $(wildcard $(OBJECTS))

cleanobjdir: cleanobjs
	$(call colorize,$(GREEN),Cleaning Objects Directory...)
	-$(CLEAN_DIR) $(DIRS)
	-$(CLEAN_DIR) $(OBJS_DIR)

cleandeps:
	$(call colorize,$(GREEN),Cleaning Dependency Files...)
	-$(CLEAN_FILES) $(wildcard $(DEPENDENCIES))

cleandepdir: cleandeps
	$(call colorize,$(GREEN),Cleaning Dependencies Directory...)
	-$(CLEAN_DIR) $(DEPS_DIR)

cleanalert:
	$(call colorize,$(GREEN),Cleaning Up...)

clean: cleanalert cleanobjdir cleandepdir

fclean: clean
	$(call colorize,$(GREEN),Cleaning Executable...)
	-$(CLEAN_FILES) $(NAME)
	-$(CLEAN_FILES) *_shrubbery

re: fclean all

-include $(DEPENDENCIES)

.phony: all debug clean fclean re compile cleanobjs cleanobjdir cleandeps cleandepdir cleanalert
