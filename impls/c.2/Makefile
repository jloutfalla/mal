CFLAGS ?= -g -O2 -Wall -Wextra -Werror -pedantic -std=c99
LDFLAGS ?= -g

#####################

SRCS = step0_repl.c step1_read_print.c step2_eval.c step3_env.c \
       step4_if_fn_do.c step5_tco.c step6_file.c step7_quote.c \
       step8_macros.c step9_try.c stepA_mal.c
OBJS = $(SRCS:%.c=%.o)
BINS = $(OBJS:%.o=%)
OTHER_OBJS = readline.o repl.o
OTHER_HDRS = readline.h repl.h

ifeq ($(shell uname -s),Darwin)
  darwin_CPPFLAGS ?= -DOSX=1
endif

# Rewrite CPPFLAGS for the Make recipes, but let existing user options
# take precedence.
override CPPFLAGS := \
  ${darwin_CPPFLAGS} ${CPPFLAGS}
override LDLIBS += \


#####################

all: $(BINS)

dist: mal

mal: $(word $(words $(BINS)),$(BINS))
	cp $< $@

$(OBJS) $(OTHER_OBJS): %.o: %.c  $(OTHER_HDRS)

$(patsubst %.o,%,$(filter step%,$(OBJS))): $(OTHER_OBJS)
$(BINS): %: %.o

clean:
	rm -f $(OBJS) $(BINS) $(OTHER_OBJS) mal
