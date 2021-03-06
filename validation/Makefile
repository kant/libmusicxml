#
# Makefile for testing the libmusicxml library
#

system := $(shell uname -s)
system := $(shell echo $(system) | grep MINGW > /dev/null && echo MINGW || echo $(system))

version	 ?= $(shell cat libmusicxmlversion.txt)
xmlfiles  = $(shell find ../files -name "*.xml")

readout    := $(patsubst ../%.xml, $(version)/read/%.xml, $(xmlfiles))
gmnout     := $(patsubst ../%.xml, $(version)/gmn/%.gmn, $(xmlfiles))
guidosvg   := $(patsubst ../%.xml, $(version)/guidosvg/%.svg, $(xmlfiles))
lilyout    := $(patsubst ../%.xml, $(version)/lilypond/%.ly, $(xmlfiles))
lilypdf    := $(patsubst ../%.xml, $(version)/lilypdf/%.pdf, $(xmlfiles))
lilypng    := $(patsubst ../%.xml, $(version)/lilypng/%.png, $(xmlfiles))
lilymidi   := $(patsubst ../%.xml, $(version)/lilypdf/%.midi, $(xmlfiles))

validxml 	    = $(patsubst %.xml, %.outxml, $(readout))
validgmn 	    = $(patsubst %.gmn, %.outgmn, $(gmnout))
validlily 	  = $(patsubst %.ly, %.outly, $(lilyout))
validguidosvg = $(patsubst %.svg, %.outsvg, $(guidosvg))
validlilypdf 	= $(patsubst %.pdf, %.outpdf, $(lilypdf))
validlilypng 	= $(patsubst %.png, %.outpng, $(lilypng))

XML2GUIDO ?= xml2guido
XML2LY    ?= xml2ly
XMLREAD   ?= xmlread
MAKE      ?= make

.PHONY: read guido
.DELETE_ON_ERROR:

all:
	$(MAKE) read
	$(MAKE) guido
	$(MAKE) lily

travis:
	$(MAKE) read
	$(MAKE) guido

trace:
	@echo $(validxml)

help:
	@echo "Makefile for testing the libmusicxml library output."
	@echo "Testing is based on the xml files located in the 'files' folder." 
	@echo "Available targets are:"
	@echo "  'all' (default): call the 'read', 'guido' and 'lily' targets."
	@echo "  'read'     : reads the set of xml files and writes the corresponding output"
	@echo "  'guido'    : converts the set of xml files to guido"
	@echo "  'lily'     : converts the set of xml files to lilypond"
	@echo "  'guidosvg' : converts the output of 'guido' target to svg"
	@echo "  'lilypng'  : converts the output of 'lily' target to png"
	@echo "  'lilypdf'  : converts the output of 'lily' target to pdf"
	@echo "Output files are written to the $(version) folder, "
	@echo "where $(version) is taken from the libmusicxmlversion.txt file that you can freely change."
	@echo 
	@echo "Validation target:"
	@echo "  'validate VERSION=another_version': compares the current version output (xml and gmn files) with the one in 'another_version' folder"
#	@echo "  (on Windows, Firefox has to be installed (and opened) in C:/Program Files (x86)/Mozilla Firefox/firefox, otherwise please change the Makefile)"
	@echo 
	@echo "Options:"
	@echo "  'XML2GUIDO=/path/to/xml2guido"
	@echo "  'XML2LY=/path/to/xml2ly"
	@echo "  'XMLREAD=/path/to/xmlread"
	@echo "when the above variables are not specified, the tools are taken from the current PATH env."

#########################################################################
read: 
	@which $(XMLREAD) > /dev/null || (echo "### xmlread (part of samples) must be available from your PATH."; false;)
	$(MAKE) doread

doread: $(readout)

#########################################################################
guido: 
	@which $(XML2GUIDO) > /dev/null || (echo "### xml2guido (part of samples) must be available from your PATH."; false;)
	$(MAKE) doguido

doguido: $(gmnout)

#########################################################################
guidosvg: 
	@which guido2svg || (echo "### guido2svg (part of guidolib project) must be available from your PATH."; false;)
	$(MAKE) guido
	$(MAKE) doguidosvg

doguidosvg: $(guidosvg)

#########################################################################
lily: 
	@which $(XML2LY) > /dev/null || (echo "### xml2ly (part of samples) must be available from your PATH."; false;)
	$(MAKE) dolily

dolily: $(lilyout)

#########################################################################
lilyclean:
	@echo "lilyout = " $(lilyout) ", " $(shell wc < echo $(lilyout))
	rm $(lilyout)

#########################################################################
lilypdf: 
	@which lilypond || (echo "### lilypond must be available from your PATH."; false;)
	$(MAKE) lily
	$(MAKE) dolilypdf

dolilypdf: $(lilypdf)

#########################################################################
lilypdfclean:
	@echo "lilypdf = " $(lilypdf) ", " $(shell wc < echo $(lilypdf))
	rm $(lilypdf)
	rm $(lilymidi)

#########################################################################
lilypng: 
	@which lilypond || (echo "### lilypond must be available from your PATH."; false;)
	$(MAKE) lily
	$(MAKE) dolilypng

dolilypng: $(lilypng)

#########################################################################
lilypngclean:
	@echo "lilypng = " $(lilypng) ", " $(shell wc < echo $(lilypng))
	rm $(lilypng)
	rm $(lilymidi)

#########################################################################
validate: 
	@echo Validating version $(version) with $(VERSION) $(tmp)
	$(MAKE) validxml
	$(MAKE) validgmn
	$(MAKE) validlily

validxml: $(validxml)

validgmn: $(validgmn)

validlily: $(validlily)

#########################################################################
# rules for xmlread
$(version)/read/%.xml: ../%.xml
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(XMLREAD) $<  > $@

#########################################################################
# rules for xml2guido
$(version)/gmn/%.gmn: ../%.xml
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(XML2GUIDO) $<  > $@ || (rm $@ ; false; )

#########################################################################
# rules for guido2svg
$(version)/guidosvg/%.svg: $(version)/gmn/%.gmn
	@[ -d $(@D) ] || mkdir -p $(@D)
	guido2svg $<  > $@

#########################################################################
# rules for xml2ly
$(version)/lilypond/%.ly: ../%.xml
	@[ -d $(@D) ] || mkdir -p $(@D)
	$(XML2LY) -q $<  > $@ || (rm $@ ; false; )
#	$(XML2LY) $<  > $@

#########################################################################
# rules for lilypond with pdf output
$(version)/lilypdf/%.pdf: $(version)/lilypond/%.ly
	@[ -d $(@D) ] || mkdir -p $(@D)
	lilypond --pdf -l NONE -s -o $(basename $@) $<

#########################################################################
# rules for lilypond with png output
$(version)/lilypng/%.png: $(version)/lilypond/%.ly
	@[ -d $(@D) ] || mkdir -p $(@D)
	lilypond --png -l NONE -s -o $(basename $@) $<

#########################################################################
# rules for xml output validation
%.outxml: %.xml
	$(eval tmp := $(patsubst $(version)/%, $(VERSION)/%, $<))
	@[ -f  $(tmp) ] || echo $< : new file
	@diff $<  $(tmp) 2>/dev/null >/dev/null || ([ -f  $(tmp) ] && echo "open -t $< $(patsubst $(version)/%, $(VERSION)/%, $<) # to check changes"; true)

%.outgmn: %.gmn
	$(eval tmp := $(patsubst $(version)/%, $(VERSION)/%, $<))
	@[ -f  $(tmp) ] || echo $< : new file
	@diff $<  $(tmp) 2>/dev/null >/dev/null || ([ -f  $(tmp) ] && echo "open -t $< $(patsubst $(version)/%, $(VERSION)/%, $<) # to check changes"; true)

%.outly: %.ly
	$(eval tmp := $(patsubst $(version)/%, $(VERSION)/%, $<))
	@[ -f  $(tmp) ] || echo $< : new file
	@diff $<  $(tmp) 2>/dev/null >/dev/null || ([ -f  $(tmp) ] && echo "open -t $< $(patsubst $(version)/%, $(VERSION)/%, $<) # to check changes"; true)
