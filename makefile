.ONESHELL:
run := pixi run

.PHONY: setup
setup:
	pixi install

.PHONY: repl
repl:
	$(run) python

.PHONY: build
build:
	xmake build

.PHONY: run
run: 
	xmake build && $(run) pysl