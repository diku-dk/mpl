## Copyright (C) 2009,2013,2018-2019 Matthew Fluet.
 # Copyright (C) 1999-2006 Henry Cejtin, Matthew Fluet, Suresh
 #    Jagannathan, and Stephen Weeks.
 # Copyright (C) 1997-2000 NEC Research Institute.
 #
 # MLton is released under a HPND-style license.
 # See the file MLton-LICENSE for details.
 ##

ROOT := ..
include $(ROOT)/Makefile.config

######################################################################

NAME := mlyacc

all:	$(NAME)

$(NAME): $(NAME).mlb $(shell "$(RUN_MLTON)" -stop f $(NAME).mlb)
	@echo 'Compiling $(NAME)'
	"$(RUN_MLTON)" @MLton $(RUN_MLTON_RUNTIME_ARGS) -- $(RUN_MLTON_COMPILE_ARGS) -target $(TARGET) $(NAME).mlb

.PHONY: clean
clean:
	$(SRC)/bin/clean

src/%.lex.sml: src/%.lex
	rm -f $<.*
	$(RUN_MLLEX) $<
	chmod -w $<.*

src/%.grm.sig src/%.grm.sml: src/%.grm
	rm -f $<.* 
	$(RUN_MLYACC) $<
	chmod -w $<.*


PDFLATEX := pdflatex

doc/mlyacc.pdf:
	$(MAKE) -C doc mlyacc.pdf

mlyacc.pdf: doc/mlyacc.pdf
	cp doc/mlyacc.pdf .

DOCS :=
ifneq ($(shell which $(PDFLATEX) 2> /dev/null),)
DOCS += mlyacc.pdf
endif

.PHONY: docs
docs: $(DOCS)


.PHONY: test
test: $(NAME)
	cp -p ../mlton/front-end/ml.grm .			\
	$(NAME) ml.grm &&					\
	$(DIFF) ml.grm.sig ../mlton/front-end/ml.grm.sig &&	\
	$(DIFF) ml.grm.sml ../mlton/front-end/ml.grm.sml	\
	rm -f ml.grm ml.grm.sig ml.grm.sml ml.grm.desc
